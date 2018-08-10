DIRS=build

all:	\
	main.c main.h \
	lista.c lista.h \
	
	gcc -o build/main.o -c main.c 
	gcc -o build/lista.o -c lista.c 


	gcc -o Programa build/main.o build/lista.o -pthread
	


		
$(shell mkdir -p $(DIRS))



