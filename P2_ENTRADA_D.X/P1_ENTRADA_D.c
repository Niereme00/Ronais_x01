/* 
 * File:   ENTRADA_D.c
 * Author: R.S.R
 * Compilador: XC8
 * Configuracion Bits: Alteri.h
 */

#include "Alteri.h"         //Configuracion de bits  

int main(){
    
    ADCON1=0b00001111;      
    TRISD=0b00011111; //# PUERTO D
    TRISB=0b00000000; //# PUERTO B
    
    while(1){
        
        if((PORTDbits.RD0=1) == 1){
            PORTBbits.RB0=1;                    
        }else{
            PORTBbits.RB0=0;
        }
        
        if((PORTDbits.RD1=1) == 1){
            PORTBbits.RB1=1;                    
        }else{
            PORTBbits.RB1=0;
        }

        if((PORTDbits.RD2=1) == 1){
            PORTBbits.RB2=1;                    
        }else{
            PORTBbits.RB2=0;
        }

        if((PORTDbits.RD3=1) == 1){
            PORTBbits.RB3=1;                    
        }else{
            PORTBbits.RB3=0;
        }

        if((PORTDbits.RD4=1) == 1){
            PORTBbits.RB4=1;                    
        }else{
            PORTBbits.RB4=0;
        }  
    }
}


