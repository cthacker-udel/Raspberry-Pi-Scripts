# Set a variable LDFLAGS. Use the variable as $(LDFLAGS)
# On cisc210.cis.udel.edu, add -lcurses to the below line
LDFLAGS := -L ~/lib -lsense -lm
INCLUDE := -I ~/include

all: etch

etch: project.h input.o output.o main.o
	cc -o etch input.o output.o main.o $(LDFLAGS) $(INCLUDE)

inputtest: project.h inputtest.o input.o
	cc -o inputtest input.o inputtest.o $(LDFLAGS) $(INCLUDE)

outputtest: project.h outputtest.o output.o
	cc -o outputtest output.o outputtest.o $(LDFLAGS) $(INCLUDE)

%.o: %.c
	cc -g -c $< $(LDFLAGS) $(INCLUDE)

run: etch
	./etch

clean:
	rm -f *.o etch inputtest outputtest
