
all: loginInterface
	echo "all complete"


loginInterface: main.o
	g++ -o loginProgram main.o


run: loginInterface
	./loginProgram


clear:
	rm -rf *.o loginProgram

%.o: %.cpp
	g++ -g -c $<

commit:
	git add -A; git commit -m 'update'; git push
