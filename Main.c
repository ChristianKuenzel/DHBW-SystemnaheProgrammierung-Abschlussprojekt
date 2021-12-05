/*
Copyright 2021, DHBW Lörrach
Systemnahe Pogrammierung, Abschlussprojekt Piano

Group #8:
Leonard Kipar <Mail> <https://github.com/leonard-kipar>
Christian Künzel <chriskuenzel@web.de> <https://github.com/ChristianKuenzel>

GitHub: <https://github.com/ChristianKuenzel/DHBW-SystemnaheProgrammierung-Abschlussprojekt>

MPLab & Prometheus
Microcontroller: PIC18F4520
*/

// Includes.
#include "Definitions.h"

// Functions.
// Calculate the time (ms) necessary to create a specific tone by formula.
int calculateTime(int note) {
    // Calculate time. Multiply by 1 million to create correct amount of ms.
    float n;
    n = ((1/note)/2)*1000000;
    
    // Round down the number by converting into integer and cutting of the rest.
    int x;
    x = (int)n;
    return x;
}

// Delay a certain amount of time.
// Needed because __delay_ms(x) only works with static numbers.
void delay_ms(int time) {
    for(int j=0; j<time; j++) {
        __delay_ms(1);
    }
}

// Create a given tone by activating the output to the speaker for a given amount of time.
void playTone(int note)
{
  // Calculate the time needed to create the tone.
  int time = calculateTime(note);
  for(int i=0; i<note; i++)
    {
        pinOutput = 0;
        delay_ms(time);
        pinOutput = 1;
        delay_ms(time);
    }
}

// Main function.
void main(void) {
    // Set APins, BPins and CPin.
    // Inputs.
    TRISA = 0b11111111;
    TRISB = 0b11111111;
    
    // Ouput
    TRISCbits.RC0 = 0;
    
    // Start loop, waiting for button/user input.
    while(1) {
        Nop();
        Nop();
        
        // Check if pin got activated. Then play tone.
        if(pinInput1 == 0){
            playTone(c);
        }
        if(pinInput2 == 0){
            playTone(cSharp);
        }
        if(pinInput3 == 0){
            playTone(d);
        }
        if(pinInput4 == 0){
            playTone(dSharp);
        }
        if(pinInput5 == 0){
            playTone(e);
        }
        if(pinInput6 == 0){
            playTone(f);
        }
        if(pinInput7 == 0){
            playTone(g);
        }
        if(pinInput8 == 0){
            playTone(a);
        }
        if(pinInput9 == 0){
            playTone(h);
        }
        if(pinInput10 == 0){
            playTone(C1);
        }
        if(pinInput11 == 0){
            playTone(D1);
        }
        if(pinInput12 == 0){
            playTone(E);
        }
        if(pinInput13 == 0){
            playTone(F);
        }
        if(pinInput14 == 0){
            playTone(G);
        }
        if(pinInput15){
            playTone(A1);
        }
        if(pinInput16){
            playTone(H);
        }
    };
    return;
}
