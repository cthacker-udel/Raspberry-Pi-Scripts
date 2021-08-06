
all: connect4

connect4: game.o board.o player.o
	cc -g -o connect4 game.o board.o player.o


%.o: %.c %.h
	cc -g -c $^


run: connect4
	./connect4

clean:
	rm -rf *.o connect4 *.gch
