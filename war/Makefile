

war: cardfunc.o game.o project.h
	cc -g -o war game.o cardfunc.o project.h



%.o: %.c
	cc -g -c $<



clean:
	rm -rf *.o war


run: war
	./war
