#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

/*
* Metodo para agregar hilos a una lista de hilos
*/
void insertar(Valor node, Valor_List list)
{

    node->prev = NULL;
    node->next = NULL;
    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
        list->tamanio += 1;
    }
    else
    {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
        list->tamanio += 1;
    }

}


/*
* Metodo para extraer el primer carro
*/
Valor pop_primer_valor(Valor_List list)
{
    if (list->head != NULL)
    {
        Valor tmp = list->head;

        if(tmp->next == NULL)
        {
            list->head = NULL;
            list->tail = NULL;
            list->tamanio -= 1;

        }
        else
        {
            tmp->next->prev = NULL;
            list->head = tmp->next;
            tmp->next = NULL;
            list->tamanio -= 1;

        }
        return tmp;

    }
    else
    {
        printf("Lista vacia\n");
        return NULL;
    }

}



/**
 * Imprime cada uno de los nodos
 **/
void imprimir(Valor_List pLista){
    printf("\n-------- LISTA Valores -------\n");
    Valor tmp = pLista->head;
    
    while(tmp != NULL) {
        printf("Numero: %d\n",tmp->numero);
        tmp = tmp->next;
        //sleep(1);
    }
    printf("\n----------------------------\n\n");
}