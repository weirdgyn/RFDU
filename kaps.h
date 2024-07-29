/** 
 * * KAPS API Header File
 *
 * Author: m.santucci
 *
 * Created on July 10, 2024, 1:00 PM
 *
 *
 * @file kaps.h
 *  
 * @defgroup kaps KAPS
 *
 * @brief Prototipi funzioni e strutture dati per la gestione del modulo KAPS.
 *
 * @version KAPS Version 1.0.0
 */

#ifndef KAPS_H
#define	KAPS_H

#include <stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define KAPS_ADDR   0x51    // KAPS board i2c slave address

    // Mappa

#define KAPS_STATUS_REG     0xFF
#define KAPS_POS_IDX_REG    0xFE
#define KAPS_CURR_POS_REG   0x00
#define KAPS_ABS_POS_REG    0x01
#define KAPS_REL_POS_REG    0x02

#define KAPS_POS1_REG       0x04
#define KAPS_POS2_REG       0x08
#define KAPS_POS3_REG       0x0C
#define KAPS_POS4_REG       0x10
    //

    typedef enum {
        KAPS_IDLE = 0x00, /**< errore di formato/messaggio sconosciuto */
        KAPS_MOVING = 0x01, /**< perirferica KAPS occupata/in movimento, NB rinominata per non sovrapporsi con error_message_t::KAPS_BUSY */
        KAPS_ERROR = 0xFF /**< errore generico (KAPS) */
    } kaps_status_t;

    /*! Struttura KAPS */
    typedef struct {
        uint8_t m_bAddr; /*!< indirizzo i2c periferica  */
        kaps_status_t m_Status; /*!< stato della periferica */
        uint32_t m_lAbsPos; /*!< valore posizione assoluta */
        uint8_t m_bIdxPos; /*!< valore indice di posizione */
    } KAPS;

    extern void KAPS_GoToIdx(uint8_t);
    extern void KAPS_setAbsPos(uint32_t);
    extern void KAPS_setRelPos(int8_t);
    extern void KAPS_StorePos(uint8_t, uint32_t);
    extern void KAPS_getStatus(void);
    extern void KAPS_getIndex(void);
    extern void KAPS_getPos(void);

    extern KAPS kaps;

#ifdef	__cplusplus
}
#endif

#endif	/* KAPS_H */

