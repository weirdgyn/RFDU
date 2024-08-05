/** 
 * * SSPA API Header File
 *
 * Author: m.santucci
 *
 * Created on July 10, 2024, 1:00 PM
 *
 *
 * @file sspa.h
 *  
 * @defgroup sspa SSPA
 *
 * @brief Prototipi funzioni e strutture dati per gestione periferiche SSPA.
 *
 * @version SSPA Version 1.0.0
 */

#ifndef SSPA_H
#define	SSPA_H

#include <stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define VDD             5 // Volts: valore di tensione di alimentazione 4.3-4.6V

    // Temperatura min, max = -40, 70 (gradi Celsius)
#define TEMP_FACTOR_N   (int32_t)(428)              // Fattore di conversione 88.54°C/V * VDD
#define TEMP_FACTOR_D   (int32_t)(4096)             // 2^12
#define TEMP_OFFSET     (int32_t)(160)              // °C offset (159,65)

    // Corrente min, max = 0, 10 (Ampere)
#define CURR_FACTOR_N   (uint16_t)(430)                 // Fattore di conversione 10A/V * VDD * 10
#define CURR_FACTOR_D   (uint16_t)(10240)               // 2^10 * 10
#define CURR_OFFSET     (uint16_t)(0)

    // Potenza RF min, max = 36, 47 (dBm)
#define PWR_FACTOR_N    (uint16_t)(14319)               // Fattore di conversione 3.33dBm/V * VDD * 1000
#define PWR_FACTOR_D    (uint16_t)(1024000)             // 2^10 * 1000
#define PWR_OFFSET      (uint16_t)(34)   

    typedef enum {
        MUTE = 1, /**< periferica non attiva */
        UNMUTE = 0 /**< periferica attiva */
    } mute_t;

    typedef enum {
        ANTENNABAND_KU = 0, // Not used
        ANTENNABAND_KA = 1,
        ANTENNABAND_X = 2
    } antenna_band_t;

    /*! Struttura SSPA */
    typedef struct {
        mute_t m_Mute;
        int16_t m_wTemp;
        uint8_t m_bPOut;
        uint32_t m_lCurrent;
    } SSPA;

    extern void SSPA_setMute(antenna_band_t, mute_t);
    extern void SSPA_getTemp(antenna_band_t);
    extern void SSPA_getPOut(antenna_band_t);

    extern SSPA sspas[];

#ifdef	__cplusplus
}
#endif

#endif	/* SSPA_H */

