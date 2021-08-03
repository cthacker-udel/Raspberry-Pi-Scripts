
all:
	connect4


connect4: main.o board.o player.o
	cc -g -o connect4 main.o board.o player.o


%.o: %.c %.h
	cc -g -c $^


clean:
	rm -rf *.o connect4 *.gch
