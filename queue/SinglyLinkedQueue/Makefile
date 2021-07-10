
all: queue



queue: main.o queueMethods.o project.h
	gcc -g -o queue main.o queueMethods.o project.h


%.o: %.c project.h
	cc -g -c $< project.h


clean:
	rm -rf queue *.o *.gch


run: queue
	./queue
