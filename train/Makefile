
main: project.h trainmethods.o main.o
	cc -g -o trainRun main.o trainmethods.o project.h


%.o: %.c project.h
	cc -g -c $< project.h

run: main
	./trainRun


clean:
	rm -rf *.o *.gch trainRun
