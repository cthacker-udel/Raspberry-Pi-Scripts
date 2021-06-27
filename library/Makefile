
compile: main.o BookMethods.o Library.o project.h
	cc -g -o exec main.o BookMethods.o Library.o project.h


%.o: %.c project.h
	cc -g -c $< project.h


clean:
	rm -rf exec *.o *.gch


run: compile
	./exec
