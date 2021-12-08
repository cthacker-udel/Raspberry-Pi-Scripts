
school: schoolMethods.o main.o project.h
	cc -g -o school schoolMethods.o main.o project.h

%.o: %.c project.h
	cc -g -c $< project.h

run: school
	./school

clean:
	rm -rf *.o school *.gch