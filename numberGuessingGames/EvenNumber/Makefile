
all:
	compile


compile: project.h main.o number.o
	cc -g -o evenNumberGame main.o number.o project.h

%.o: %.c
	cc -g -c $<

run: compile
	./evenNumberGame