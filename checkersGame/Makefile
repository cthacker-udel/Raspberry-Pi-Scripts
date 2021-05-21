LDFLAGS:= -L ~/lib -lsense -lm
INCLUDE:= -I ~/include

all: checkers

checkers: checkers.h checkers.o input.o output.o
	cc -g -o checkers checkers.o checkers.h

%.o: %.c
	cc -g -c $<
