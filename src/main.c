/**


**/


#include "main.h"
#include "lista.h"

// Genera un numero aleatorio dentro de un rango
int randomNum(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

// Metodo ejecutado por el Hilo 1 
void* proceso1(){
    while(1){
        usleep(100000);
        int numero = randomNum(0, 255);
        Valor val = (Valor) calloc(1,sizeof(struct valor));
        val -> numero = numero;
        insertar(val,lista);
    }

    return NULL;
}

// Metodo ejecutado por el Hilo 2
void* proceso2(){
    while(1){
	if(lista -> tamanio > 0) {
		Valor val = pop_primer_valor(lista);
		int numero = val -> numero;
		int operA = numero^32;
		printf(ANSI_COLOR_RED "Valor leido de la lista: " ANSI_COLOR_RESET);
		printf(ANSI_COLOR_GREEN "%hhu\n" ANSI_COLOR_RESET, operA);
	}
    }
    return NULL;
}


// Entrada principal del sistema
int main()
{
    printf(ANSI_COLOR_MAGENTA "Inicializando sistema\n" ANSI_COLOR_RESET);

    lista = (Valor_List) calloc(1,sizeof(struct valor_list));

    // configuracion de la semilla del random
    srand(time(0));
 
    // creacion del hilo generador de numeros 
    if(pthread_create(&thread_P1, NULL, proceso1, NULL)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    // creacion del hilo aplicador de XOR 
    if(pthread_create(&thread_P2, NULL, proceso2, NULL)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }
	
    // Inicializacion del mutex lock
    if(pthread_mutex_init(&lock_thread_array, NULL) != 0)
    {
        printf("\n mutex init failed\n");
    }


    /* wait for the second thread to finish */
    if(pthread_join(thread_P1, NULL)) {
        fprintf(stderr, "Error joining thread\n");
        return 2;
    }


    /* espera hasta que el hilo sea finalizado */
    if(pthread_join(thread_P2, NULL)) {
        fprintf(stderr, "Error joining thread\n");
        return 2;
    }

    // Destruccion del candado mutex lock
    pthread_mutex_destroy(&lock_thread_array);
}


