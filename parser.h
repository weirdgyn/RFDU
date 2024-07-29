/** 
 * * Parser Header File
 *
 * Author: m.santucci
 *
 * Created on July 10, 2024, 1:00 PM
 *
 *
 * @file parser.h
 *  
 * @defgroup parser PARSER
 *
 * @brief Prototipi funzioni e strutture dati per la gestione del parser del protocollo RFDU (EUSART).
 *
 * @version Parser Version 1.0.0
 */

#ifndef PARSER_H
#define	PARSER_H

#include <stdint.h>
#include <stdbool.h>

#ifdef	__cplusplus
extern "C" {
#endif
#define OVERHEAD        3   // bytes: 1 SoM + 1 MsgId + 1 Checksum 

#define MAX_DATA_LEN    5   // bytes
#define MAX_REPLY_LEN   6   // bytes

#define MAX_MSG_LEN     (OVERHEAD+MAX_REPLY_LEN)

#define SoM         0x01

    typedef enum {
        WAIT_SOM = 0x00, /**< attesa di SoM */
        WAIT_ID = 0x01, /**< attesa dell'identificatore del messaggio */
        WAIT_VALUE = 0x02, /**< attesa del blocco dati/payload del messaggio */
        WAIT_CKSUM = 0x03 /**< attesa del valore checksum */
    } parser_status_t;

    typedef enum {
        CKSUM_ERR = 0x01, /**< errore di checksum */
        WRONG_MESSAGE = 0x02, /**< errore di formato/messaggio sconosciuto */
        KAPS_BUSY = 0x03, /**< perirferica KAPS occupata/in movimento */
        SSPA_FAIL = 0x04, /**< failure della periferica SSPA */
        GENERIC_ERROR = 0x05 /**< errore generico */
    } error_message_t;

    typedef enum {
        NVT_RFDU_SetMute = 0x01,
        NVT_RFDU_GetMute = 0x02,
        NVT_RFDU_SSPATemp = 0x03,
        NVT_RFDU_SSPAPout = 0x04,
        NVT_RFDU_KapsStatus = 0x05,
        NVT_RFDU_ReadAbsPos = 0x06,
        NVT_RFDU_GoToPos = 0x07,
        NVT_RFDU_TuneSetAP = 0x08,
        NVT_RFDU_TuneSetRP = 0x09,
        NVT_RFDU_TuneSetPos = 0x0A,
        NVT_RFDU_ReadPosIdx = 0x11,

        RFDU_NVT_MuteStatus = 0x0C,
        RFDU_NVT_SSPATemp = 0x0D,
        RFDU_NVT_SSPAPout = 0x0E,
        RFDU_NVT_KapsStatus = 0x0F,
        RFDU_NVT_KapsAbsPos = 0x10,
        RFDU_NVT_KapsIdxPos = 0x12,

        RFDU_NVT_NACK = 0x0B
    } msg_id_t;

    typedef struct {
        parser_status_t m_State; /*!< stato del parser */
        msg_id_t m_MsgID; /*!< ultimo id ricevuto */
        uint8_t m_bDataIndex; /*!<byte dati corrente */
        uint8_t m_bDataSize; /*!< dati da ricevere  */
        uint8_t m_bReplySize; /*!< dimensione della risposta  */
        uint8_t m_bCkSum; /*!< valore checksum ricevuto */
        uint8_t m_bSum; /*!< valore checksum calcolato */
        bool m_bEcho; /*!< flag invio echo comando */
    } Parser;

    extern void SendMsg(uint8_t, uint8_t*, uint8_t);
    extern bool Parse(uint8_t);
    extern void EUSART_sendMsg(const char*, int);

    extern Parser parser;
    extern uint8_t parserDataBuffer[];
    
#ifdef	__cplusplus
}
#endif

#endif	/* PARSER_H */

