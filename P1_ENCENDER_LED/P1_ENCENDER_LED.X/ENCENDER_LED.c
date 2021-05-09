/* 
 * File:   ENCENDER_LED.c
 * Author: R.S.R
 *              
 * Compilador: XC8
 * Configuracion Bits: Alteri.h
 */

#include "Alteri.h"         //Configuracion de bits  

int main(){
    
    ADCON1=0b00001111;      // #1
    TRISD=0b00000000;       // #2 
    
    while(1){
                
        PORTDbits.RD0=1;    // #3
        delay_ms(500);      // #4
        PORTDbits.RD0=0;    
        delay_ms(500);     
    }
}


/*
 * #1
 * Para entradas digitales.
 * 
 * #2
 * Indicarle al puerto "D" con TRIS + "D" que todos los pines funcionaran como salida, el  
 * numero "0" significa salida, "1" como entrada.
 * 
 * #3
 * Para indicar el pin que queremos activar debemos escribir PORT + "LETRA DEL PUERTO" + "bits" ,
 * seguido de un punto escribiendo R+"LETRA DEL PUERTO" = "1" o "0" ENCENDIDO O APAGADO.
 * 
 * #4
 * Para el tiempo de espera se escribe "delay_ms(500);", el numero dentro del parentesis es el tiempo en milisegundos.
 * 
 * 
 * 
 
 */