/*
 * File:   Main.c
 * Author: Leonard Kipar & Christian Martin Künzel
 *
 * Created on 1. Dezember 2021, 9:31
 */


#include "Definitions.h"

int calculateTime(int note) {
    float n;
    n = ((1/note)/2)*1000000;
    int x;
    x = (int)n;
    return x;
}

void delay_ms(int time) {
    for(int j=0; j<time; j++) {
        __delay_ms(1);
    }
}

void playTone(int note)
{
  int time = calculateTime(note);
  for(int i=0; i<note; i++)
    {
        pinOutput = 0;
        delay_ms(time);
        pinOutput = 1;
        delay_ms(time);
    }
}

void main(void) {
    //Constructor
    TRISA = 0b11111111;
    TRISB = 0b11111111;  
    TRISCbits.RC0 = 0; //RC0 = Output
    
    while(1) {
        Nop();
        Nop();
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