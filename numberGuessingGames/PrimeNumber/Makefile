
exec: main.o number.o project.h
	cc -g -o game number.o main.o project.h

%.o: %.c project.h
	cc -g -c $< project.h

run: exec
	./random_number_script.sh


clean:
	rm -rf *.o game 
