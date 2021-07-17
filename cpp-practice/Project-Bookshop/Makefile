

all: bookstore
	echo "Build Success!"


bookstore: main.o Book.o Store.o
	g++ -o bookstore main.o Book.o Store.o


run: bookstore
	./bookstore


clean:
	rm -rf *.o bookstore *.exe


%.o: %.cpp
	g++ -g -c $<


commit:
	git add -A; git commit -m 'update'; git push
