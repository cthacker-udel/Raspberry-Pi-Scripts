
all: compile
	echo "All complete"

compile: Student.o main.o Class.o School.o District.o City.o State.o 
	g++ -o runfile main.o Student.o Class.o School.o District.o City.o State.o

run: compile
	./runfile

clean:
	rm -rf *.o runfile


%.o : %.cpp
	g++ -g -c $<


quick-commit:
	git add -A; git commit; git push
