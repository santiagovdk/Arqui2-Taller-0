/*H**********************************************************************
* FILENAME :        lista.c             
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


#include <pthread.h>

#ifndef _LISTA_H
#define _LISTA_H


typedef struct valor
{
    int numero;
    struct valor *next;
    struct valor *prev;
} *Valor;

typedef struct valor_list
{
	Valor head;
	Valor tail;
	int tamanio;
} *Valor_List;


void insertar(Valor node, Valor_List list);
Valor pop_primer_valor(Valor_List list);
void imprimir(Valor_List pLista);


#endif
