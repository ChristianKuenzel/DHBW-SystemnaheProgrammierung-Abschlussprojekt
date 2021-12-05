/*
Copyright 2021, DHBW Loerrach
Systemnahe Pogrammierung, Abschlussprojekt Piano

Group #8:
Leonard Kipar <leonard.kipar@gmail.com> <https://github.com/leonard-kipar>
Christian Kuenzel <chriskuenzel@web.de> <https://github.com/ChristianKuenzel>

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
void playTone(int note) {
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

// Play a random melody out of 2 by playing tones sequently out of a fixed array.
void playMelody() {
    // Choose random melody.
    int random = rand() % 2 + 1;
    
    // Melody
    // Happy Birthday.
    int melody1[] = {a,a,h,a,d,cis,a,a,h,a,e,d,a,a,a,fis,d,cis,h,g,g,fis,d,e,d,a,a,h,a,d,cis,a,a,h,a,e,d,a,a,a,fis,d,cis,d,cis,h,g,g,fis,d,e,d};
    // Boogi Woogi.
    int melody2[] = {c,e,g,a,h,a,g,e,c,e,g,a,b,a,g,e,F,A1,c,d,es,d,e,A1,c,e,g,a,b,a,g,e,G,H,d,H,F,A1,c,A1,c,e,g,a,b,a,g,e};
    
    // Play chosen melody.
    if(random == 1) {
        size_t n = sizeof(melody1) / sizeof(melody1[0]);
        for(int m = 0; m < n; m++) {
            playTone(melody1[m]);
            delay_ms(1000);
        }
    }
    
    if(random == 2) {
        size_t n = sizeof(melody2) / sizeof(melody2[0]);
        for(int m = 0; m < n; m++) {
            playTone(melody2[m]);
            delay_ms(1000);
        }
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
            playTone(cis);
        }
        if(pinInput3 == 0){
            playTone(d);
        }
        if(pinInput4 == 0){
            playTone(dis);
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
        // Check if pin got activated. Then play melody.
        if(pinMelody){
            playMelody();
        }
    };
    return;
}
