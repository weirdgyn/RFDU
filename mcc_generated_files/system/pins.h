/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.0.0
*/

/*
© [2024] Microchip Technology Inc. and its subsidiaries.

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

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RA0 aliases
#define PD_X_TRIS                 TRISAbits.TRISA0
#define PD_X_LAT                  LATAbits.LATA0
#define PD_X_PORT                 PORTAbits.RA0
#define PD_X_WPU                  WPUAbits.WPUA0
#define PD_X_OD                   ODCONAbits.ODA0
#define PD_X_ANS                  ANSELAbits.ANSA0
#define PD_X_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define PD_X_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define PD_X_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define PD_X_GetValue()           PORTAbits.RA0
#define PD_X_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define PD_X_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define PD_X_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define PD_X_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define PD_X_SetPushPull()        do { ODCONAbits.ODA0 = 0; } while(0)
#define PD_X_SetOpenDrain()       do { ODCONAbits.ODA0 = 1; } while(0)
#define PD_X_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define PD_X_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)
// get/set IO_RA1 aliases
#define CS_Ka_TRIS                 TRISAbits.TRISA1
#define CS_Ka_LAT                  LATAbits.LATA1
#define CS_Ka_PORT                 PORTAbits.RA1
#define CS_Ka_WPU                  WPUAbits.WPUA1
#define CS_Ka_OD                   ODCONAbits.ODA1
#define CS_Ka_ANS                  ANSELAbits.ANSA1
#define CS_Ka_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define CS_Ka_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define CS_Ka_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define CS_Ka_GetValue()           PORTAbits.RA1
#define CS_Ka_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define CS_Ka_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define CS_Ka_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define CS_Ka_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define CS_Ka_SetPushPull()        do { ODCONAbits.ODA1 = 0; } while(0)
#define CS_Ka_SetOpenDrain()       do { ODCONAbits.ODA1 = 1; } while(0)
#define CS_Ka_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define CS_Ka_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)
// get/set IO_RA4 aliases
#define TM_Ka_TRIS                 TRISAbits.TRISA4
#define TM_Ka_LAT                  LATAbits.LATA4
#define TM_Ka_PORT                 PORTAbits.RA4
#define TM_Ka_WPU                  WPUAbits.WPUA4
#define TM_Ka_OD                   ODCONAbits.ODA4
#define TM_Ka_ANS                  ANSELAbits.ANSA4
#define TM_Ka_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define TM_Ka_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define TM_Ka_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define TM_Ka_GetValue()           PORTAbits.RA4
#define TM_Ka_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define TM_Ka_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define TM_Ka_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define TM_Ka_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define TM_Ka_SetPushPull()        do { ODCONAbits.ODA4 = 0; } while(0)
#define TM_Ka_SetOpenDrain()       do { ODCONAbits.ODA4 = 1; } while(0)
#define TM_Ka_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define TM_Ka_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)
// get/set IO_RB4 aliases
#define CS_X_TRIS                 TRISBbits.TRISB4
#define CS_X_LAT                  LATBbits.LATB4
#define CS_X_PORT                 PORTBbits.RB4
#define CS_X_WPU                  WPUBbits.WPUB4
#define CS_X_OD                   ODCONBbits.ODB4
#define CS_X_ANS                  ANSELBbits.ANSB4
#define CS_X_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define CS_X_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define CS_X_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define CS_X_GetValue()           PORTBbits.RB4
#define CS_X_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define CS_X_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define CS_X_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define CS_X_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define CS_X_SetPushPull()        do { ODCONBbits.ODB4 = 0; } while(0)
#define CS_X_SetOpenDrain()       do { ODCONBbits.ODB4 = 1; } while(0)
#define CS_X_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define CS_X_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)
// get/set IO_RB5 aliases
#define SDA_TRIS                 TRISBbits.TRISB5
#define SDA_LAT                  LATBbits.LATB5
#define SDA_PORT                 PORTBbits.RB5
#define SDA_WPU                  WPUBbits.WPUB5
#define SDA_OD                   ODCONBbits.ODB5
#define SDA_ANS                  ANSELBbits.ANSB5
#define SDA_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define SDA_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define SDA_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define SDA_GetValue()           PORTBbits.RB5
#define SDA_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define SDA_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define SDA_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define SDA_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define SDA_SetPushPull()        do { ODCONBbits.ODB5 = 0; } while(0)
#define SDA_SetOpenDrain()       do { ODCONBbits.ODB5 = 1; } while(0)
#define SDA_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define SDA_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)
// get/set IO_RB6 aliases
#define SCL_TRIS                 TRISBbits.TRISB6
#define SCL_LAT                  LATBbits.LATB6
#define SCL_PORT                 PORTBbits.RB6
#define SCL_WPU                  WPUBbits.WPUB6
#define SCL_OD                   ODCONBbits.ODB6
#define SCL_ANS                  ANSELBbits.ANSB6
#define SCL_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define SCL_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define SCL_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define SCL_GetValue()           PORTBbits.RB6
#define SCL_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define SCL_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define SCL_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define SCL_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define SCL_SetPushPull()        do { ODCONBbits.ODB6 = 0; } while(0)
#define SCL_SetOpenDrain()       do { ODCONBbits.ODB6 = 1; } while(0)
#define SCL_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define SCL_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)
// get/set IO_RC1 aliases
#define RX_TRIS                 TRISCbits.TRISC1
#define RX_LAT                  LATCbits.LATC1
#define RX_PORT                 PORTCbits.RC1
#define RX_WPU                  WPUCbits.WPUC1
#define RX_OD                   ODCONCbits.ODC1
#define RX_ANS                  ANSELCbits.ANSC1
#define RX_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RX_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RX_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RX_GetValue()           PORTCbits.RC1
#define RX_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RX_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RX_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define RX_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define RX_SetPushPull()        do { ODCONCbits.ODC1 = 0; } while(0)
#define RX_SetOpenDrain()       do { ODCONCbits.ODC1 = 1; } while(0)
#define RX_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define RX_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)
// get/set IO_RC2 aliases
#define TX_TRIS                 TRISCbits.TRISC2
#define TX_LAT                  LATCbits.LATC2
#define TX_PORT                 PORTCbits.RC2
#define TX_WPU                  WPUCbits.WPUC2
#define TX_OD                   ODCONCbits.ODC2
#define TX_ANS                  ANSELCbits.ANSC2
#define TX_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define TX_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define TX_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define TX_GetValue()           PORTCbits.RC2
#define TX_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define TX_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define TX_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define TX_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define TX_SetPushPull()        do { ODCONCbits.ODC2 = 0; } while(0)
#define TX_SetOpenDrain()       do { ODCONCbits.ODC2 = 1; } while(0)
#define TX_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define TX_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)
// get/set IO_RC3 aliases
#define TM_X_TRIS                 TRISCbits.TRISC3
#define TM_X_LAT                  LATCbits.LATC3
#define TM_X_PORT                 PORTCbits.RC3
#define TM_X_WPU                  WPUCbits.WPUC3
#define TM_X_OD                   ODCONCbits.ODC3
#define TM_X_ANS                  ANSELCbits.ANSC3
#define TM_X_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define TM_X_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define TM_X_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define TM_X_GetValue()           PORTCbits.RC3
#define TM_X_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define TM_X_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define TM_X_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define TM_X_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define TM_X_SetPushPull()        do { ODCONCbits.ODC3 = 0; } while(0)
#define TM_X_SetOpenDrain()       do { ODCONCbits.ODC3 = 1; } while(0)
#define TM_X_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define TM_X_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)
// get/set IO_RC6 aliases
#define EN_X_TRIS                 TRISCbits.TRISC6
#define EN_X_LAT                  LATCbits.LATC6
#define EN_X_PORT                 PORTCbits.RC6
#define EN_X_WPU                  WPUCbits.WPUC6
#define EN_X_OD                   ODCONCbits.ODC6
#define EN_X_ANS                  ANSELCbits.ANSC6
#define EN_X_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define EN_X_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define EN_X_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define EN_X_GetValue()           PORTCbits.RC6
#define EN_X_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define EN_X_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define EN_X_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define EN_X_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define EN_X_SetPushPull()        do { ODCONCbits.ODC6 = 0; } while(0)
#define EN_X_SetOpenDrain()       do { ODCONCbits.ODC6 = 1; } while(0)
#define EN_X_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define EN_X_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)
// get/set IO_RC7 aliases
#define EN_Ka_TRIS                 TRISCbits.TRISC7
#define EN_Ka_LAT                  LATCbits.LATC7
#define EN_Ka_PORT                 PORTCbits.RC7
#define EN_Ka_WPU                  WPUCbits.WPUC7
#define EN_Ka_OD                   ODCONCbits.ODC7
#define EN_Ka_ANS                  ANSELCbits.ANSC7
#define EN_Ka_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define EN_Ka_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define EN_Ka_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define EN_Ka_GetValue()           PORTCbits.RC7
#define EN_Ka_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define EN_Ka_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define EN_Ka_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define EN_Ka_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define EN_Ka_SetPushPull()        do { ODCONCbits.ODC7 = 0; } while(0)
#define EN_Ka_SetOpenDrain()       do { ODCONCbits.ODC7 = 1; } while(0)
#define EN_Ka_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define EN_Ka_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)
/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/