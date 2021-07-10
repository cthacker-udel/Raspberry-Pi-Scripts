all: priorityQueue

priorityQueue: main.o queueMethods.o project.h
	cc -g -o priorityQueue main.o queueMethods.o project.h


%.o: %.c project.h
	cc -g -c $< project.h


clean:
	rm -rf *.o *.gch priorityQueue

run: priorityQueue
	./priorityQueue


