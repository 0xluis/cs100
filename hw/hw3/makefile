#mainSOURCES
MAINS=linuxio.o fork_prog.o testString.o
HEADERS=String.h Timer.h
CFLAGS=g++ -g -c
EXEC=linuxio fork_prog testString

all: $(HEADERS) $(MAINS) $(EXEC)

testString: testString.o String.o
	g++ -g testString.o String.o -o testString

testString.o: testString.cc String.cc String.h
	$(CFLAGS) String.cc testString.cc

String.o: String.h String.cc
	$(CFLAGS) String.cc

linuxio: linuxio.o
	g++ -g linuxio.o -o linuxio

linuxio.o: linuxio.cc Timer.h
	$(CFLAGS) linuxio.cc

fork_prog: fork_prog.o
	g++ -g fork_prog.o -o fork_prog

fork_prog.o: fork_prog.cc
	$(CFLAGS) fork_prog.cc

clean:
	rm -rf *.o $(EXEC)
