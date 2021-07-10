

stack: main.o stackmethods.o project.h
	cc -g -o stack main.o stackmethods.o project.h

%.o: %.o project.h
	cc -g -c $< project.h


clean:
	rm -rf *.o *.gch stack

run: stack
	./stack
