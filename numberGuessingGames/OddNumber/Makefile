
all:
	compile


compile: project.h main.o number.o
	cc -g -o oddNumberGame main.o number.o project.h

%.o: %.c
	cc -g -c $<

run: compile
	./oddNumberGame

clean:
	rm -rf *.o oddNumberGame
