all: Tarea3

Tarea3: main.o interprete.o TDA.o
	g++ -Wall -o Tarea3 main.o interprete.o TDA.o

main.o: main.cpp interprete.h TDA.h
	g++ -Wall -c main.cpp

interprete.o: interprete.cpp
	g++ -Wall -c interprete.cpp

TDA.o: TDA.cpp
	g++ -Wall -c TDA.cpp
	
clean:
	rm *.o Tarea3
