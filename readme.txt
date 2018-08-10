Arquitectura de Computadores 2
Ing. M.Sc. Jeferson González Gómez
Taller 0: Hilos 
Santiago Vargas de Kruijf	
2013050807
Viernes 10 Agosto 2018

Preguntas
1) Investigue posibles métodos (biblioteas, apis, etc) para el uso de hilos bajo el sistema operativo GNU Linux. P.e. pthread
Cuando se utiliza un entorno linux es posibles utilizar la biblioteca Pthread pero esto requiere de la bandera "-pthread" para poder realizar
el compilado del programa. Esta biblioteca es nativa y basada POSIX, la cual está una API llamada "POSIX Threads" la cual cumple con el estandard POSIX.1c


2) ¿Qué métodos existen para compartir memoria (variables globales) de manera segura entre hilos?
Para el manejo seguro de variables globales se utilizan cerrojos Mutex los cuales también son proporcionados por el API de POSIX Threads,
estos cerrojos requieren una inicialización al igual que los hilos. Estos cerrojos poseen un método lock y unlock, estos metodos deben de ser llamados
antes de comenzar a ejecutar un codigo el cual solo deberia de ser ejecutado por un hilo a la vez. En caso de que un hilo desee hacer lock de un cerrojo
que ya fue bloqueado por otro hilo el primer hilo deberá esperar hasta que el segundo hilo llame al metodo unlock del cerrojo. Debe quedar claro que esto
puede crear un Deadlock en caso de que el segundo hilo nunca llame el metodo unlock.



Ejecución del programa
1) Abrir la terminal.
2) Hacer "cd" hasta el directorio principal.
3) cd /src
4) make
5) De ser necesario por errores de permisos ejecutar "chmod +x Programa"
6) ./Programa

La salida del programa especifica el valor leido cada vez de la lista.

Nota: Para cancelar la ejecución del programa presionar "Ctrl + C"
