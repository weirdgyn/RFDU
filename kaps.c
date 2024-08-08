/*
 * KAPS board management
 * 
 * @file kaps.c
 * 
 * @defgroup kaps KAPS
 * 
 * @brief Implementazione funzioni e variabili globali per la gestione del modulo KAPS.
 *
 * @version KAPS Version 1.0.0
 */

#include "kaps.h"

#include "mcc_generated_files/i2c_host/mssp.h"
#include "utils.h"

KAPS kaps = {KAPS_ADDR, KAPS_IDLE, 0x00000000, 0x00};

static uint8_t buffer[8];

/**
 * @brief Imposta la posizione di indice idx sulla periferica kaps (tramite bus i2c).
 * @param idx indice di posizione
 */
void KAPS_GoToIdx(uint8_t idx) {
    buffer[0] = KAPS_POS_IDX_REG;
    buffer[1] = idx;

    I2C1_Write(kaps.m_bAddr, buffer, 2);
    //TODO attende KAPS.m_Status == KAPS_MOVING ?
}

/**
 * @brief Imposta la posizione assoluta pos sulla periferica kaps (tramite bus i2c).
 * @param pos posizione assoluta
 */
void KAPS_setAbsPos(uint32_t pos) {
    buffer[0] = KAPS_ABS_POS_REG;

    unpackLong(pos, buffer + 1);

    I2C1_Write(kaps.m_bAddr, buffer, 5);
    //TODO attende KAPS.m_Status == KAPS_MOVING ?
}

/**
 * @brief Imposta la posizione relativa offset sulla periferica kaps (tramite bus i2c).
 * @param offset posizione relativa
 */
void KAPS_setRelPos(int8_t offset) {
    buffer[0] = KAPS_REL_POS_REG;
    buffer[1] = (uint8_t) offset;

    I2C1_Write(kaps.m_bAddr, buffer, 2);
    //TODO attende KAPS.m_Status == KAPS_MOVING ?
}

/**
 * @brief Memorizza la posizione assoluta pos all'indice idx sulla periferica kaps (tramite bus i2c).
 * @param idx indice di posizione
 * @param pos posizione assoluta
 */
void KAPS_StorePos(uint8_t idx, uint32_t pos) {
    idx--; // indici a base 0

    uint8_t reg = (idx)*4 + KAPS_POS1_REG;

    buffer[0] = reg;
    buffer[1] = idx;
    unpackLong(pos, buffer + 2);

    I2C1_Write(kaps.m_bAddr, buffer, 6);
}

/**
 * @brief Acquisisce lo stato della periferica kaps (tramite bus i2c).
 */
void KAPS_getStatus() {
    uint8_t reg = (uint8_t) (KAPS_STATUS_REG | RD_BIT);
    uint8_t data = 0x00;

    I2C1_Write(kaps.m_bAddr, &reg, 1);

    if (I2C1_Read(kaps.m_bAddr, &data, 1))
        kaps.m_Status = (kaps_status_t) data;
}

/**
 * @brief Acquisisce l'indice di posizione della periferica kaps (tramite bus i2c).
 */
void KAPS_getIndex() {
    uint8_t reg = (uint8_t) (KAPS_POS_IDX_REG | RD_BIT);
    uint8_t data = 0x00;

    I2C1_Write(kaps.m_bAddr, &reg, 1);

    if (I2C1_Read(kaps.m_bAddr, &data, 1))
        kaps.m_bIdxPos = data;
}

/**
 * @brief Acquisisce la posizione assoluta della periferica kaps (tramite bus i2c).
 */
void KAPS_getPos() {
    uint8_t reg = (uint8_t) (KAPS_CURR_POS_REG | RD_BIT);
    uint8_t data[4] = {0x00, 0x00, 0x00, 0x00}; //TODO endianism?

    I2C1_Write(kaps.m_bAddr, &reg, 1);

    if (I2C1_Read(kaps.m_bAddr, data, 4))
        kaps.m_lAbsPos = packLong(data);
}