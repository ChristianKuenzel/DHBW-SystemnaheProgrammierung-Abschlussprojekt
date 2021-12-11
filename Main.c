/*
Copyright 2021, DHBW Loerrach
Systemnahe Pogrammierung, Abschlussprojekt Piano

Group #8:
Leonard Kipar <leonard.kipar@gmail.com> <https://github.com/leonard-kipar>
Christian Kuenzel <chriskuenzel@web.de> <https://github.com/ChristianKuenzel>

GitHub: <https://github.com/ChristianKuenzel/DHBW-SystemnaheProgrammierung-Abschlussprojekt>

MPLab & Proteus
Microcontroller: PIC18F4520
*/

// Includes.
#include "Definitions.h"

// Functions.
// Calculate the time (ms) necessary to create a specific tone by formula.
float n;
int x;
int calculateTime(int note) {
    // Calculate time. Multiply by 1 million to create correct amount of ms.
    n = ( ( ( 1 / note ) / 2 ) * 1000000 );
    
    // Round down the number by converting into integer and cutting of the rest.
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
int time;
int i;
void playTone(int note) {
  // Calculate the time needed to create the tone.
  time = calculateTime(note);
  for(i=0; i<note; i++)
    {
        pinOutput = 0;
        delay_ms(time);
        pinOutput = 1;
        delay_ms(time);
    }
}


// Play a random melody out of 2 by playing tones sequently out of a fixed array.
/*void playMelody() {
    // Choose random melody.
    int random = rand() % 2 + 1;
    
    // Melody
    // Happy Birthday.
    int melody1[] = {a,a,h,a,d,cis,a,a,h,a,e,d,a,a,a,fis,d,cis,h,g,g,fis,d,e,d,a,a,h,a,d,cis,a,a,h,a,e,d,a,a,a,fis,d,cis,d,cis,h,g,g,fis,d,e,d};
    // Boogi Woogi.
    int melody2[] = {c,e,g,a,h,a,g,e,c,e,g,a,b,a,g,e,F,A1,c,d,es,d,e,A1,c,e,g,a,b,a,g,e,G,H,d,H,F,A1,c,A1,c,e,g,a,b,a,g,e};
    
    // Play chosen melody.
    if(random == 1) {
        int n = sizeof(melody1) / sizeof(melody1[0]);
        for(int m = 0; m < n; m++) {
            playTone(melody1[m]);
        }
    }
    
    if(random == 2) {
        int n = sizeof(melody2) / sizeof(melody2[0]);
        for(int m = 0; m < n; m++) {
            playTone(melody2[m]);
        }
    }
}*/

// Main function.
void main(void) {
    // Set APins, BPins and CPin.
    // Inputs.
    TRISD = 0b11111111;
    TRISB = 0b11111111;
    
    // Ouput
    TRISCbits.RC0 = 0;
    
    // Start loop, waiting for button/user input.
    while(1) {
        // Check if pin got activated. Then play tone.
        if(pinInput1 == 1){
            playTone(c);
            Nop();
        }
        if(pinInput2 == 1){
            playTone(cis);
            Nop();
        }
        if(pinInput3 == 1){
            playTone(d);
            Nop();
        }
        if(pinInput4 == 1){
            playTone(dis);
            Nop();
        }
        if(pinInput5 == 1){
            playTone(e);
            Nop();
        }
        if(pinInput6 == 1){
            playTone(f);
            Nop();
        }
        if(pinInput7 == 1){
            playTone(g);
            Nop();
        }
        if(pinInput8 == 1){
            playTone(a);
            Nop();
        }
        if(pinInput9 == 1){
            playTone(h);
            Nop();
        }
        if(pinInput10 == 1){
            playTone(C1);
            Nop();
        }
        if(pinInput11 == 1){
            playTone(D1);
            Nop();
        }
        if(pinInput12 == 1){
            playTone(E);
            Nop();
        }
        if(pinInput13 == 1){
            playTone(F);
            Nop();
        }
        if(pinInput14 == 1){
            playTone(G);
            Nop();
        }
        if(pinInput15 == 1){
            playTone(A1);
            Nop();
        }
        if(pinInput16 == 1){
            playTone(H);
            Nop();
        }
        // Check if pin got activated. Then play melody.
        /*if(pinMelody == 1){
            playMelody();
            Nop();
        }*/
    };
    return;
}
