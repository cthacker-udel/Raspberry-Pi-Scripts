SHELL:=/bin/bash
LDFLAGS := -L ~/lib -lsense -lm
INCLUDE := -I ~/include

all: poker

poker: project.h input.o output.o main.o pokercombos.o
	cc -o poker input.o output.o pokercombos.o main.o $(LDFLAGS) $(INCLUDE)


inputtest: input.o inputtest.o project.h
	cc -o inputtest input.o inputtest.o


outputtest: output.o outputtest.o project.h
	cc -o outputtest outputtest.o output.o


%.o: %.c
	cc -g -c $< $(LDFLAGS) $(INCLUDE)


run: poker
	./random_poker.sh


clean:
	rm -rf *.o poker inputtest outputtest
