
game: main.o number.o project.h
	cc -g -o game main.o number.o project.h

%.o: %.c project.h
	cc -g -c $< project.h

run: game
	./random_number_script

clean:
	rm -rf *.o *.gch game
