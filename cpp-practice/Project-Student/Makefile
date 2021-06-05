
all: compile



compile: Student.o main.o
	g++ -o runfile main.o Student.o

run: compile
	./runfile

clean:
	rm -rf *.o runfile


%.o : %.cpp
	g++ -g -c $<


quick-commit:
	git add -A; git commit; git push
