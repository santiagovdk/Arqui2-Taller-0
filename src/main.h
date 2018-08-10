/*H**********************************************************************
* FILENAME :        main.c             
*
* DESCRIPTION :
*       Algoritmos para el manejo de arreglos dinamicos.
*
* PUBLIC FUNCTIONS :
*       void     insertar( Valor, Valor_List )
*       Valor    pop_primer_valor( Valor_List )
*	void     imprimit( Valor_List )
*
* NOTES :
*
*
* AUTHOR :    Santiago Vargas de Kruijf        START DATE :    9 Agosto 2018
*
*
*H*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <pthread.h>
#include "lista.h"



#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


pthread_t thread_P1;        // Thread para el hilo creador de numeros
pthread_t thread_P2;        // Thread para el hilo para operar XOR
pthread_mutex_t lock_thread_array;      // Mutex para prevenir escritura simulatanea
Valor_List lista;			// Variable global para el manejo de la lista


int randomNum(int lower, int upper);
void* proceso1();
void* proceso2();



#endif // MAIN_H_INCLUDED
