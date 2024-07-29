/** 
 * * Utils Header File
 *
 * Author: m.santucci
 *
 * Created on July 10, 2024, 1:00 PM
 *
 *
 * @file utils.h
 *  
 * @defgroup utils UTILS
 *
 * @brief Prototipi funzioni di supporto.
 *
 * @version Utils Version 1.0.0
 */
#ifndef UTILS_H
#define	UTILS_H

#include <stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif

    extern uint32_t packLong(uint8_t*);
    extern uint16_t packWord(uint8_t*);
    extern void unpackLong(uint32_t, uint8_t*);
    extern void unpackWord(uint16_t, uint8_t*);

#ifdef	__cplusplus
}
#endif

#endif	/* UTILS_H */

