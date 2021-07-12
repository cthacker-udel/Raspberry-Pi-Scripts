
all: rentalsystem
	echo "Build Success!"


rentalsystem: main.o Car.o User.o Rent.o
	g++ -o rentalsystem main.o Car.o User.o Rent.o


run: rentalsystem
	./rentalsystem

clean:
	rm -rf *.o rentalsystem *.exe


%.o: %.cpp
	g++ -g -c $<


commit:
	git add -A; git commit -m 'update'; git push
