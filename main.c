/*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
 */

/*
� [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
 */
#include "mcc_generated_files/system/system.h"
#include <string.h>
#include "kaps.h"
#include "utils.h"
#include "parser.h"
#include "sspa.h"

//#define SEND_HELLO

/**
 * @brief Processa il messaggio identificato da msg_id e dal buffer data.
 * @param msg_id
 * @param data
 */
void ProcessMsg(uint8_t msg_id, uint8_t* data) {
    static uint8_t payload[MAX_REPLY_LEN];

    switch (msg_id) {
        case NVT_RFDU_GetMute:
            payload[0] = data[0];
            payload[1] = (uint8_t) sspas[data[0]].m_Mute;
            SendMsg(RFDU_NVT_MuteStatus, payload, 2);
            break;

        case NVT_RFDU_SSPATemp:
            SSPA_getTemp((antenna_band_t) data[0]);
            payload[0] = data[0];
            unpackWord((uint16_t) sspas[data[0]].m_wTemp, &payload[1]);
            SendMsg(RFDU_NVT_SSPATemp, payload, 3);
            break;

        case NVT_RFDU_SSPAPout:
            SSPA_getPOut((antenna_band_t) data[0]);
            payload[0] = data[0];
            payload[1] = sspas[data[0]].m_bPOut;
            unpackLong(sspas[data[0]].m_lCurrent, &payload[2]);
            SendMsg(RFDU_NVT_SSPAPout, payload, 6);
            break;

        case NVT_RFDU_KapsStatus:
            KAPS_getStatus();
            payload[0] = (uint8_t) kaps.m_Status;
            SendMsg(RFDU_NVT_KapsStatus, payload, 1);
            break;

        case NVT_RFDU_ReadAbsPos:
            KAPS_getPos();
            unpackLong(kaps.m_lAbsPos, payload);
            SendMsg(RFDU_NVT_KapsAbsPos, payload, 4);
            break;

        case NVT_RFDU_ReadPosIdx:
            KAPS_getIndex();
            payload[0] = kaps.m_bIdxPos;
            SendMsg(RFDU_NVT_KapsIdxPos, payload, 1);
            break;

        case NVT_RFDU_SetMute:
            SSPA_setMute((antenna_band_t) data[0], (mute_t) data[1]);
            break;

        case NVT_RFDU_GoToPos:
            KAPS_GoToIdx(data[0]);
            break;

        case NVT_RFDU_TuneSetAP:
            KAPS_setAbsPos(packLong(data));
            break;

        case NVT_RFDU_TuneSetRP:
            KAPS_setRelPos((int8_t) data[0]);
            break;

        case NVT_RFDU_TuneSetPos:
            KAPS_StorePos(data[4], packLong(data));
            break;
    }
}

/*
    Main application
 */
int main(void) {
    SYSTEM_Initialize();

    INTERRUPT_GlobalInterruptEnable();

    //INTERRUPT_GlobalInterruptDisable(); 

    INTERRUPT_PeripheralInterruptEnable();

    //INTERRUPT_PeripheralInterruptDisable(); 

#ifdef SEND_HELLO
    EUSART_sendMsg("RFDU", 4);
#endif
    uint8_t data = 0x00;

    for (;;) {
        if (EUSART_IsRxReady()) {
            data = EUSART_Read();

            if (Parse(data))
                ProcessMsg(parser.m_MsgID, parserDataBuffer);
        } else
            NOP();
    }
}