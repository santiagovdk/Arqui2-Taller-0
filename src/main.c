#include "main.h"
#include "lista.h"

int convertToBin(int dec)
{
    if (dec == 0)
    {
        return 0;
    }
    else{
        return (dec % 2 + 10 * convertToBin(dec / 2));
    }
}

// Genera un numero aleatorio dentro de un rango
int randomNum(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

void* proceso1(){
    while(1){
        printf("Proceso 1\n");
        sleep(1);
        int numero = randomNum(0, 255);
        fprintf("Generated: %i", numero);
        Valor val = (Valor) calloc(1,sizeof(struct valor));
        val -> numero = numero;
        insertar(val,lista);
    }

    return NULL;
}


void* proceso2(){
    while(1){
        printf("Proceso 2\n");
        sleep(2);
    }
    
    return NULL;
}

/*
* Entrada principal del sistema
*/
int main()
{
    
    printf("Iniciando sistema\n");

    lista = (Valor_List) calloc(1,sizeof(struct valor_list));

    // Use current time as 
    // seed for random generator
    srand(time(0));
 
    
    /* create a second thread which executes inc_x(&x) */
    if(pthread_create(&thread_P1, NULL, proceso1, NULL)) {

        fprintf(stderr, "Error creating thread\n");
        return 1;

    }

    /* create a second thread which executes inc_x(&x) */
    if(pthread_create(&thread_P2, NULL, proceso2, NULL)) {

        fprintf(stderr, "Error creating thread\n");
        return 1;

    }


    if(pthread_mutex_init(&lock_thread_array, NULL) != 0)
    {
        printf("\n mutex init failed\n");
    }


    /* wait for the second thread to finish */
    if(pthread_join(thread_P1, NULL)) {

        fprintf(stderr, "Error joining thread\n");
        return 2;
    }


    /* wait for the second thread to finish */
    if(pthread_join(thread_P2, NULL)) {

        fprintf(stderr, "Error joining thread\n");
        return 2;
    }

    pthread_mutex_destroy(&lock_thread_array);
}


