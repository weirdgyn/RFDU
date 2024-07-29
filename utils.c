/*
 * UTILS
 * 
 * @file utils.c
 * 
 * @defgroup utils UTILS
 * 
 * @brief Implementaizone funzioni di supporto.
 *
 * @version UTILS Version 1.0.0
 */

#include "utils.h"

/**
 * @brief 'Impacchetta' l'array di byte data (4 bytes) in una unsinged long.
 * @param data.
 * @return valore su unsigned long.
 */
uint32_t packLong(uint8_t* data) {
    //TODO endianism?
    uint32_t result;

    result = 0x00000000;

    result = (uint32_t) data[0] << 24;
    result |= (uint32_t) data[1] << 16;
    result |= (uint32_t) data[2] << 8;
    result |= (uint32_t) data[3];

    return result;
}

/**
 * @brief 'Impacchetta' l'array di byte data (2 bytes) in una unsinged word.
 * @param data.
 * @return valore su unsigned word.
 */
uint16_t packWord(uint8_t* data) {
    //TODO endianism?
    uint16_t result;

    result = 0x0000;

    result |= (uint16_t) data[0] << 8;
    result |= (uint16_t) data[1];

    return result;
}

/**
 * @brief 'Spacchetta' il valore passato (unsigned long) in un'array di byte (4).
 * @param value
 * @param data
 * @sa packLong
 */
void unpackLong(uint32_t value, uint8_t* data) {
    //TODO endianism?    
    data[0] = (value & 0XFF);
    data[1] = (value >> 8) & 0xFF;
    data[2] = (value >> 16) & 0xFF;
    data[3] = (value >> 24) & 0xFF;
}

/**
 * @brief 'Spacchetta' il valore passato (unsigned word) in un'array di byte (2).
 * @param value
 * @param data
 * @sa packWord
 */
void unpackWord(uint16_t value, uint8_t* data) {
    //TODO endianism?
    data[0] = value & 0xFF;
    data[1] = (value >> 8) & 0xFF;
}