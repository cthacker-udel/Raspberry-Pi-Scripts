
all: compile
	echo "All Complete"

compile: Rectangle.o Circle.o Triangle.o
	g++ -o runfile main.o Rectangle.o Circle.o Triangle.o

run: compile
	./runfile

clean:
	rm -rf *.o runfile

%.o : %.cpp
	g++ -g -c $<

commit:
	git add -A; git commit; git push
