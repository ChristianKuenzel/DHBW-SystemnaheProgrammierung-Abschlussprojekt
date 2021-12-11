/*
Copyright 2021, DHBW LÃ¶rrach
Systemnahe Pogrammierung, Abschlussprojekt Piano

Group #8:
Leonard Kipar <Mail> <https://github.com/leonard-kipar>
Christian KÃ¼nzel <chriskuenzel@web.de> <https://github.com/ChristianKuenzel>

GitHub: <https://github.com/ChristianKuenzel/DHBW-SystemnaheProgrammierung-Abschlussprojekt>

MPLab & Proteus
Microcontroller: PIC18F4520
*/

// Configuration Settings
#define _XTAL_FREQ 4000000

// Buttons
// Pins are defined as digital input in main.c
// For each button pressed is a seperat pin available.
#define pinInput1 PORTDbits.RD0
#define pinInput2 PORTDbits.RD1
#define pinInput3 PORTDbits.RD2
#define pinInput4 PORTDbits.RD3
#define pinInput5 PORTDbits.RD4
#define pinInput6 PORTDbits.RD5
#define pinInput7 PORTDbits.RD6
#define pinInput8 PORTDbits.RD7
#define pinInput9 PORTBbits.RB0
#define pinInput10 PORTBbits.RB1
#define pinInput11 PORTBbits.RB2
#define pinInput12 PORTBbits.RB3
#define pinInput13 PORTBbits.RB4
#define pinInput14 PORTBbits.RB5
#define pinInput15 PORTBbits.RB6
#define pinInput16 PORTBbits.RB7
// Pin to play a fix melody.
#define pinMelody PORTCbits.RC1

// Speaker
// Pin is defined as digital output in main.c
#define pinOutput PORTCbits.RC0

// Define every note with its Hz number.
// The amount of Hz is used to create the tone.
#define c 261
#define cis 277
#define d 293
#define dis 311
#define e 329
#define f 349
#define g 392
#define a 440
#define h 493
#define C1 523
#define D1 587
#define E 659
#define F 698
#define G 784
#define A1 880
#define H 987
// Needed for melody not used by any button.
#define fis 369
#define es 311
#define b 466

// Further standard configuration.
// CONFIG1H
#pragma config OSC = HSPLL      // Oscillator Selection bits (HS oscillator, PLL enabled (Clock Frequency = 4 x FOSC1))
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bits (Brown-out Reset disabled in hardware and software)
#pragma config BORV = 3         // Brown Out Reset Voltage bits (Minimum setting)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = PORTC   // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = ON         // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled)
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
