# Author - cthacker-udel

LDFLAGS:= -L ~/lib -lsense -lm
INCLUDE:= -I ~/include

all: checkers

checkers: checkers.h checkers.o input.o output.o
	cc -g -o checkers checkers.o input.o output.o checkers.h $(LDFLAGS) $(INCLUDE)

%.o: %.c
	cc -g -c $< $(LDFLAGS) $(INCLUDE)

run: checkers
	./checkers


clean:
	rm -rf *.o checkers
