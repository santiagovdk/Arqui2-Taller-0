Arquitectura de Computadores 2
Ing. M.Sc. Jeferson González Gómez
Taller 0: Hilos 
Santiago Vargas de Kruijf	
2013050807
Viernes 10 Agosto 2018

Preguntas
1) Investigue posibles métodos (biblioteas, apis, etc) para el uso de hilos bajo el sistema operativo GNU Linux. P.e. pthread
Cuando se utiliza un entorno linux es posibles utilizar el API Pthread basada en "POSIX Threads" la cual cumple con el estandard POSIX.1c
La compilación de esta biblioteca requiere la bandera -pthread en el proceso de compilado.


2) ¿Qué métodos existen para compartir memoria (variables globales) de manera segura entre hilos?
Para el manejo seguro de variables globales se utilizan cerrojos MUTEX los cuales también son proporcionados por el API de POSIX Threads,
estos cerrojos requieren una inicialización al igual que los hilos. Su funcionamiento es el siguiente, cada vez que
se desee proteger un bloque de código que se comparta entre varios hilos se utilizan cerrojos para bloquear o desbloquear
la entrada a esta "Región crítica" para ello se llaman los metodos principales lock() y unlock() del cerrojo.



Ejecución del programa
1) Abrir la terminal.
2) Hacer "cd" hasta el directorio principal.
3) cd /src
4) make
5) De ser necesario por errores de permisos ejecutar "chmod +x Programa"
6) ./Programa

La salida del programa especifica el valor leido cada vez de la lista.

Nota: Para cancelar la ejecución del programa presionar "Ctrl + C"
