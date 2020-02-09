/*
 * File:   final.c
 * Author: HC-CHAN
 *
 * Created on 2019?12?28?, ?? 9:35
 */


// PIC18F4520 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1H
#pragma config OSC = INTIO67    // Oscillator Selection bits (Internal oscillator block, port function on RA6 and RA7)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = ON        // Internal/External Oscillator Switchover bit (Oscillator Switchover mode enabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 3         // Brown Out Reset Voltage bits (Minimum setting)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 1        // Watchdog Timer Postscale Select bits (1:1)

// CONFIG3H
#pragma config CCP2MX = PORTC   // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <pic18f4520.h>
#define _XTAL_FREQ 125000
int i,j,k = 0;
void main(void) {
    LATDbits.LATD3 = 0;
    RCONbits.IPEN = 1;
    INTCONbits.GIE = 1;
    INTCONbits.INT0E = 1;
    INTCONbits.INT0F = 0;
    TRISBbits.RB0 = 1;
    PORTB = 0x00;
    TRISC = 0x00;
    TRISD = 0x00;
    TRISDbits.RD0 = 1;
    TRISDbits.RD1 = 1;
    OSCCONbits.IRCF2 = 0;
    OSCCONbits.IRCF1 = 0;
    OSCCONbits.IRCF0 = 1;
    //T2CONbits.T2OUTPS = 15;
    T2CONbits.TMR2ON = 1;
    //T2CONbits.T2CKPS1 = 1;
    PR2 = 0xff;
    
    CCP1CONbits.CCP1M = 12;
    CCP1CONbits.DC1B = 0;
    CCPR1L = 0x00;
    j=0;
    i=0;
    while(1){
        /*if(i<255&&j==0)i++;
        else j=1;
        if(j==1&&i>1) i--;
        else j=0;
        CCPR1L = i;
        __delay_ms(10);
        if(PORTBbits.RB0==1){
            if(i<120)i++;
            else if(i>0) i--;
            CCPR1L = i;
            __delay_ms(10);
        }*/
            
        if(PORTBbits.RB0==1){
            if(i<255)i++;
            CCPR1L = i;
            __delay_ms(10);
            LATDbits.LATD2 = 1;
            LATDbits.LATD3 = 1;
        }else{
            i = 0;
            CCPR1L = i;
            if(PORTDbits.RD1==1) {
                LATDbits.LATD2 = 1;
                LATDbits.LATD3 = 0;
            }
            else if(PORTDbits.RD0==1) {
                LATDbits.LATD2 = 0;
                LATDbits.LATD3 = 1;
            }else{
                LATDbits.LATD2 = 0;
                LATDbits.LATD3 = 0;
            }
        }
    };
    return;
}
void __interrupt(high_priority) Hi_ISR(void)
{
    if(PORTBbits.RB0==1) {
        i = 0;
    }
    /*LATDbits.LATD2 = 1;
    LATDbits.LATD3 = 1;*/
    INTCONbits.INT0IF = 0;
    PORTB = 0x00;
    return ;
}