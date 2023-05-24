

all: war

war: card.o main.o project.h
	cc -g -o war main.o card.o project.h



%.o: %.c
	cc -g -c $<



clean:
	rm -rf *.o war


run: war
	./war
