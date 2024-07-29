/*
 * SSPA
 * 
 * @file sspa.c
 * 
 * @defgroup sspa SSPA
 * 
 * @brief Implementazione funzioni e strutture dati per gestione periferiche SSPA.
 *
 * @version SSPA Version 1.0.0
 */

#include "sspa.h"

#include "mcc_generated_files/adc/adc.h"
#include "mcc_generated_files/system/pins.h"

SSPA sspas[3] = {
    {MUTE, 0x0000, 0x00, 0x00000000},
    {MUTE, 0x0000, 0x00, 0x00000000},
    {MUTE, 0x0000, 0x00, 0x00000000}
};

/**
 * @brief Acquisisce il valore del canale specificato facendo la media su 32 acqusizioni.
 * 
 *  La funzione restituisce il valore acquisito dal canale specificato 
 *  come parametro eseguendo la media su 32 acqusizioni. 
 *  Data la velocità dell'acqusizione, l'allineamento del valore (destro)
 *  acquisito e la risoluzione dell'ADC (10 bit) possono essere sommati
 *  64 samples per ogni intero a 16 bit senza rischio di 
 *  overflow. Al termine dell'acqusizione il risultato della somma dei 
 *  samples (32) viene shiftato a destra di 5 bit.
 * @param channel.
 * @return valore acqusito.
 */
adc_result_t getADCValue(adc_channel_t channel) {
    adc_result_t sum = 0;

    ADC_StartConversion();
    ADC_SelectChannel(channel);

    for (uint8_t i = 0; i < 32; i++)
        if (ADC_IsConversionDone())
            sum += ADC_GetConversionResult();

    return sum >> 5; // Divide per 32 tramite shift
}

int16_t ADC2Celsius(adc_result_t v) {
    int32_t value = (int32_t) v;
    int32_t result = TEMP_OFFSET - (value * TEMP_FACTOR_N) / TEMP_FACTOR_D;

    return (int16_t) result;
}

uint32_t ADC2Amp(adc_result_t v) {
    int32_t value = (int32_t) v;
    int32_t result = CURR_OFFSET + (value * CURR_FACTOR_N) / CURR_FACTOR_D;

    return (uint32_t) result;
}

uint8_t ADC2dBm(adc_result_t v) {
    int32_t value = (int32_t) v;
    int32_t result = PWR_OFFSET + (value * PWR_FACTOR_N) / PWR_FACTOR_D;

    return (uint8_t) result;
}

/**
 * @brief Imposta il valore dei pin EN_Ka, EN_X e dei campi della struttura globale sspas in funzione dei parametri band e mute.
 * @param band
 * @param mute
 */
void SSPA_setMute(antenna_band_t band, mute_t mute) {
    switch (band) {
        case ANTENNABAND_KA:
            if (mute == UNMUTE)
                EN_Ka_SetHigh();
            else
                EN_Ka_SetLow();
            break;

        case ANTENNABAND_X:
            if (mute == UNMUTE)
                EN_X_SetHigh();
            else
                EN_X_SetLow();
            break;

        case ANTENNABAND_KU:
        default:
            break;
    }

    sspas[band].m_Mute = mute;
}

/**
 * @brief Acquisisce il valore di temperatura (in gradi Celsius) della periferica SSPA determinata dal parametro band e lo memorizza nella struttura globale sspas.
 * @param band
 */
void SSPA_getTemp(antenna_band_t band) {
    adc_channel_t channel;
    adc_result_t adc_value;

    switch (band) {
        case ANTENNABAND_KA:
            channel = TM_Ka;

            break;
        case ANTENNABAND_X:
            channel = TM_X;
            break;

        case ANTENNABAND_KU:
        default:
            break;
    }

    adc_value = getADCValue(channel);

    sspas[band].m_wTemp = ADC2Celsius(adc_value);
}

/**
 * @brief Acquisisce il valore di potenza (in dBm) della periferica SSPA determinata dal parametro band e lo memorizza nella struttura globale sspas.
 * @param band
 */
void SSPA_getPOut(antenna_band_t band) {
    adc_channel_t channel;
    adc_result_t adc_value;

    switch (band) {
        case ANTENNABAND_KA:
            channel = CS_Ka;
            adc_value = getADCValue(channel);
            sspas[band].m_lCurrent = ADC2Amp(adc_value);
            sspas[band].m_bPOut = 0xFF;
            break;

        case ANTENNABAND_X:
            channel = CS_X;
            adc_value = getADCValue(channel);
            sspas[band].m_lCurrent = ADC2Amp(adc_value);
            channel = PD_X;
            adc_value = getADCValue(channel);
            sspas[band].m_bPOut = (uint8_t) ADC2dBm(adc_value);
            break;

        case ANTENNABAND_KU:
        default:
            break;
    }
}