all: tarea6

tarea6: main.o quickSort.o bubbleSort.o
	g++ -Wall -o tarea6 main.o quickSort.o bubbleSort.o

main.o: main.cpp bubbleSort.h quickSort.h
	g++ -Wall -c main.cpp

bubbleSort.o: bubbleSort.cpp
	g++ -Wall -c bubbleSort.cpp

quickSort.o: quickSort.cpp
	g++ -Wall -c quickSort.cpp

clean:
	rm *.o tarea6