build:
	doggame


doggame: board.o game.o player.o board.h player.h
	cc -g -o doggame game.o player.o board.o


%.o: %.c %.h
	cc -g -c $^ 



run: doggame
	./doggame


clean:
	rm -rf *.o doggame *.gch
