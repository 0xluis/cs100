#mainSOURCES
MAINS=my_shell.o testMatrix.o
HEADERS=Array.h Matrix.h
CFLAGS=g++ -g -c
EXEC=my_shell testMatrix

all: $(HEADERS) $(MAINS) $(EXEC)

testMatrix:
	g++ -g testMatrix.o -o testMatrix

testMatrix.o: $(HEADERS)
	$(CFLAGS) testMatrix.cpp

my_shell: my_shell.o
	g++ -g my_shell.o -o my_shell

my_shell.o: my_shell.cc
	$(CFLAGS) my_shell.cc

clean:
	rm -rf *.o $(EXEC)
