/* 
 * File:   Alteri.h
 * Compañia: Dignal
 * Version: 2.0
 * Procesador: PIC18F4550 | Placa Alteri
 *
 * Compiladores: Microchip C18 v3.40 o mayor
 *               Microchip XC8 
 *               CCS PCH: PIC18 Compiler
 *               HI-TECH PIC18
 * 
 * ************************* Actualizaciones *************************************
 *Apartir de la versión 1.35, el compilador XC8 no incluye en su
 *carpeta de instalación las librerías de periféricos llamadas
 *"PLIB", dentro de estos archivos se encuentraba el header"delays.h"
 *que da soporte a las funciones de retardo utilizadas en la versión 1.0 
 *del encabezado "Alteri.h".

 *Estos archivos de librería de periféricos PLIB habían estado presentes 
 *en XC8 con el propósito de mantener la compatibilidad con C18. Por lo cuál, 
 *en esta versión de "Alteri.h" se crea una nueva rutina de retardos 
 *utilizando el mecanismo propio de XC8 "__delay_ms()" y la ruitna 
 *de retardos anterior queda utilizable únicamente para el compilador C18.

 *Es posible descargar la librería de periféricos PLIB desde el sitio web
 *de Microchip: http://www.microchip.com/pagehandler/en_us/devtools/mplabxc/
 * *******************************************************************************
 */

#ifndef ALTERI_H
#define	ALTERI_H

/********** Definiciones de compiladores *******************/

#if defined(__18CXX) && !defined(__PCH__) && !defined(__XC8) && !defined(HI_TECH_C)
    #define COMPILER_C18
    #include <p18cxxx.h>
#elif defined(__XC8) && !defined(__18CXX) && !defined(__PCH__) 
    #define COMPILER_XC8
    #include<xc.h>
#elif defined(__PCH__) && !defined(__18CXX) && !defined(__XC8) && !defined(HI_TECH_C)
    #define COMPILER_CCS
    #include <18F4550.h>
#elif defined(__PICC18__) && defined(HI_TECH_C) && !defined(__18CXX) && !defined(__PCH__)
    #if !defined(__18CXX)
	#define __18CXX
    #endif
    #define COMPILER_HITECH
    #include <htc.h>
#else
    #error "Compilador desconocido. Ver Alteri.h"
#endif
/*************************************************************************/
/***********************Definiciones de I/O*******************************/
#if defined(COMPILER_C18) || defined(COMPILER_XC8) || defined(COMPILER_HITECH)/*Compatible para C18,XC8 y HITECH PIC18*/

#define LD0 LATDbits.LATD0  /*Etiquieta para LED LD0*/
#define LD1 LATDbits.LATD1  /*Etiquieta para LED LD1*/
#define LD2 LATDbits.LATD2  /*Etiquieta para LED LD2*/
#define LD3 LATDbits.LATD3  /*Etiquieta para LED LD3*/
#define S2  PORTBbits.RB4   /*Etiqueta para pulsador S2. Cambiar JP7 para habilitar*/
#define S3  PORTBbits.RB5   /*Etiqueta para pulsador S3*/

#endif
/*************************************************************************/
/************ Configuracion del oscilador. Cristal de 20 MHz ************/

#if defined(COMPILER_C18) || defined(COMPILER_XC8) || defined(COMPILER_HITECH)/*Compatible para C18,XC8 y HITECH PIC18*/
    #if !defined (CLOCK_48MHZ)&&!defined(CLOCK_32MHZ)&&!defined(CLOCK_24MHZ)&&!defined(CLOCK_20MHZ)&&!defined(CLOCK_16MHZ) &&!defined(CLOCK_10MHZ)&&!defined(CLOCK_6_67MHZ) && !defined(CLOCK_5MHZ)
        #define CLOCK_48MHZ
        #define _XTAL_FREQ 48000000
        #warning "FRECUENCIA DE OPERACION DEFINIDA A 48 MHZ POR DEFAULT"
    #endif
    #ifdef CLOCK_48MHZ
        #define _XTAL_FREQ 48000000
        #pragma config CPUDIV   = OSC1_PLL2
        #pragma config FOSC     = HSPLL_HS

    #elif defined CLOCK_32MHZ
        #define _XTAL_FREQ 32000000
        #pragma config CPUDIV   = OSC2_PLL3
        #pragma config FOSC     = HSPLL_HS

    #elif defined CLOCK_24MHZ
        #define _XTAL_FREQ 24000000
        #pragma config CPUDIV   = OSC3_PLL4
        #pragma config FOSC     = HSPLL_HS

    #elif defined CLOCK_20MHZ
        #define _XTAL_FREQ 20000000
        #pragma config CPUDIV   = OSC1_PLL2
        #pragma config FOSC     = HS

    #elif defined CLOCK_16MHZ
        #define _XTAL_FREQ 16000000
        #pragma config CPUDIV   = OSC4_PLL6
        #pragma config FOSC     = HSPLL_HS

    #elif defined CLOCK_10MHZ
        #define _XTAL_FREQ 10000000
        #pragma config CPUDIV   = OSC2_PLL3
        #pragma config FOSC     = HS

    #elif defined CLOCK_6_67MHZ
        #define _XTAL_FREQ 6670000
        #pragma config CPUDIV   = OSC3_PLL4
        #pragma config FOSC     = HS

    #elif defined CLOCK_5MHZ
        #define _XTAL_FREQ 5000000
        #pragma config CPUDIV   = OSC4_PLL6
        #pragma config FOSC     = HS
    #endif
#endif

/**********************************************************************************/
/******************************Bits de configuracion ******************************/
#if defined(COMPILER_C18) || defined(COMPILER_XC8) || defined(COMPILER_HITECH)
        #pragma config PLLDIV = 5,USBDIV=2,FCMEN= OFF,IESO=OFF,PWRT=OFF,BOR=ON
        #pragma config BORV=3,VREGEN=ON,WDT=OFF,WDTPS=32768,MCLRE=ON,LPT1OSC=OFF
        #pragma config PBADEN=OFF,STVREN=ON,LVP=OFF,XINST=OFF,CP0=OFF,CP1=OFF
        #pragma config CPB=OFF,WRT0=OFF,WRT1=OFF,WRTB=OFF,WRTC=OFF
        #pragma config EBTR0=OFF,EBTR1 = OFF,EBTRB = OFF
        /** No cambiar los valores de PLLDIV, USBDIV y VREGEN para evitar fallas **/

#elif defined(COMPILER_CCS)
        #fuses CPUDIV1,HSPLL,NOWDT,NOPROTECT,NOLVP,NODEBUG,USBDIV,PLL5,VREGEN
        /** No cambiar los valores para evitar fallas **/
#endif

/*************************************************************************************
 *****************************Mapeo de Vectores*************************************/

/* Para los compiladores XC8 y HI-TECH PIC18 es necesario configurar manualmente
 la opción CODEOFFSET con el valor de 0x1000.
 * En MPLAB X: Ir a Properties->Linker->Aditional optiones->Code offset
 * En MPLAB v8xx: Ir a Project->Build Options->Project->Linker->Code offset
 */

#if defined(COMPILER_C18)
	extern void _startup (void);        // Ver c018i.c
	#pragma code _RESET_VECTOR = 0x1000
	void _reset (void)
	{
	    _asm goto _startup _endasm
	}
    #pragma code

#elif defined(COMPILER_CCS)
        #build (reset=0x1000, interrupt=0x1008) /*Remapeo de vectores de Reset e Interrupciones*/
        #org 0, 0xFFF {}   /*Reservar área de memoria ocupada por el Bootloader de Alteri*/
#endif
/******************************************************************************************************/
/***************************** Funciones de retardos **************************************************/
    
#if defined(COMPILER_XC8) 
    extern void delay_ms(long int n)
    {
        while(n-- !=0){
            __delay_ms(1);
        }
    }
#endif
    
#if defined (COMPILER_C18)
    extern void delay_ms( int i )
    {
	long int j;
	for(j=0;j<i;j++)
	{
            #ifdef CLOCK_48MHZ
                Delay1KTCYx(12); //1 ms aprox
            #elif defined (CLOCK_32MHZ)
                Delay1KTCYx(8);//1 ms aprox
            #elif defined CLOCK_24MHZ
                Delay1KTCYx(6);//1 ms aprox
            #elif defined CLOCK_20MHZ
                Delay1KTCYx(5);//1 ms aprox
            #elif defined CLOCK_16MHZ
                Delay1KTCYx(4);//1 ms aprox
            #elif defined CLOCK_10MHZ
                Delay1KTCYx(2); Delay100TCYx(5);//1 ms aprox
            #elif defined CLOCK_6_67MHZ
                Delay1KTCYx(1); Delay100TCYx(6);Delay10TCYx(6); //1660 TCY
                Nop(); Nop(); Nop(); Nop(); Nop();              //+5 TCY 1ms aprox
            #elif defined CLOCK_5MHZ
                Delay1KTCYx(1); Delay100TCYx(2);Delay10TCYx(5); //1250 TCY 1ms aprox
            #endif
	}
    }
#define delay_us	Delay10TCYx

#endif

#endif	/* ALTERI_H */

