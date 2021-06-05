
all: compile
	echo "All complete"

compile: Student.o main.o Class.o School.o
	g++ -o runfile main.o Student.o Class.o School.o

run: compile
	./runfile

clean:
	rm -rf *.o runfile


%.o : %.cpp
	g++ -g -c $<


quick-commit:
	git add -A; git commit; git push
