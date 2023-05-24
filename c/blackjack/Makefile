CARD:=cardAR.o

all: game

%.o: %.c card.h
	cc -g -c $<

game: card.h game.o $(CARD)
	cc -g -o game game.o $(CARD)

run: game
	./game

clean:
	rm -f game *.o
