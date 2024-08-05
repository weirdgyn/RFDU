/*
 * Parser
 * 
 * @file parser.c
 * 
 * @defgroup parser PARSER
 * 
 * @brief Implementazione funzioni e variabili globali per la gestione del parser del protocollo RFDU (EUSART) 
 *
 * @sa RFDU_IDD_1.0.doc.
 *
 * @version Parser Version 1.0.0
 */

#include "parser.h"

#include <stdbool.h>
#include "mcc_generated_files/uart/eusart.h"

uint8_t parserDataBuffer[MAX_DATA_LEN];
Parser parser = {WAIT_SOM, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, false};

void SendSync(uint8_t data)
{
    while(!EUSART_IsTxReady())
        NOP();
    EUSART_Write(data);    
}

/**
 * @brief Invia un messaggio identificato da msg_id, data tramite la periferica EUSART.
 * @param msg_id id messaggio
 * @param data buffer dati
 * @param data_len dimensione buffer dati
 */
void SendMsg(uint8_t msg_id, uint8_t* data, uint8_t data_len) {
    uint8_t sum = 0x00;

    SendSync(SoM);

    SendSync(msg_id);

    if (msg_id == RFDU_NVT_NACK)
    {
        SendSync(*data);
        return;
    }
    
    for (; data_len > 0; data_len--) {
        SendSync(*data);
        sum += *data;
        data++;
    }

    SendSync(sum); // Write checksum
}

/**
 * @brief Invia un messaggio RFDU_NVT_NACK con relativo codice error.
 * @param error codice errore da inviare
 */
void SendNack(uint8_t error) {
    SendMsg(RFDU_NVT_NACK, &error, 1);
}

/**
 * @brief Processa il byte data per decodificare un messaggio ricevuto tramite la periferica EUSART.
 * La procedura implementa un automa a stati finiti che decodifica il protocollo definito nel 
 * documento RFDU_IDD_1.0.doc.
 * Il risultato della decodifica e' memorizzato nella strutttura globale parser.
 * @param data carattere da processare
 * @return true se il messaggio è stato completato e deve essere processato, false altrimenti
 */
bool Parse(uint8_t data) {
    switch (parser.m_State) {
        case WAIT_SOM:
            if (data == SoM) {
                parser.m_State = WAIT_ID;
                parser.m_bSum = 0x00;
                parser.m_bDataIndex = 0;
            } else
                SendNack(WRONG_MESSAGE);
            break;

        case WAIT_ID:
            parser.m_MsgID = data;
            parser.m_bEcho = true;

            parser.m_State = WAIT_VALUE;

            switch ((uint8_t) parser.m_MsgID) {
                case NVT_RFDU_KapsStatus:
                case NVT_RFDU_ReadAbsPos:
                case NVT_RFDU_ReadPosIdx:
                    parser.m_bEcho = false;
                    parser.m_bReplySize = 0;
                    parser.m_bDataSize = 0;
                    parser.m_State = WAIT_CKSUM;
                    break;

                case NVT_RFDU_GetMute:
                case NVT_RFDU_SSPATemp:
                case NVT_RFDU_SSPAPout:
                case NVT_RFDU_TuneSetRP:
                    parser.m_bEcho = false;
                case NVT_RFDU_GoToPos:
                    parser.m_bReplySize = 1;
                    parser.m_bDataSize = 1;
                    break;

                case NVT_RFDU_SetMute:
                    parser.m_bReplySize = 2;
                    parser.m_bDataSize = 2;
                    break;

                case NVT_RFDU_TuneSetAP:
                    parser.m_bReplySize = 4;
                    parser.m_bDataSize = 4;
                    break;

                case NVT_RFDU_TuneSetPos:
                    parser.m_bReplySize = 5;
                    parser.m_bDataSize = 5;
                    break;
                    
                default:
                    parser.m_State = WAIT_SOM;
            }
            break;

        case WAIT_VALUE:
            parserDataBuffer[parser.m_bDataIndex] = data;
            parser.m_bSum += data;
            parser.m_bDataIndex++;
            parser.m_bDataSize--;
            if (parser.m_bDataSize == 0)
                parser.m_State = WAIT_CKSUM;
            break;

        case WAIT_CKSUM:
            parser.m_bCkSum = data;
            parser.m_State = WAIT_SOM;

            if (parser.m_bSum == parser.m_bCkSum) {
                if (parser.m_bEcho)
                    SendMsg(parser.m_MsgID, parserDataBuffer, parser.m_bReplySize);

                return true;
            } else
                SendNack(CKSUM_ERR);
            break;

        default:
            SendNack(WRONG_MESSAGE);
            parser.m_State = WAIT_SOM;
    }
    
    return false;
}

/**
 * @brief Invia la stringa buffer tramite seriale.
 * N.B. è possibile inviare stringhe statiche.
 * @param buffer string da inviare
 * @param len  lunghezza stringa
 */
void EUSART_sendMsg(const char* buffer, int len)
{
    for(int i=0; i<len;)
    {
        if(EUSART_IsTxReady())
        {
            uint8_t data;
            
            data = (uint8_t)(*buffer);
            
            EUSART_Write(data);
            buffer++;
            i++;
        }
        else
            NOP();
    }
}