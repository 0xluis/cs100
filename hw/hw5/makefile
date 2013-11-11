#mainSOURCES
MAINS=my_shell.o handle_signals.o testLinkedString.o
HEADERS=String.h
CFLAGS=g++ -g -c
EXEC=my_shell handle_signals testLinkedString

all: $(HEADERS) $(MAINS) $(EXEC)

testLinkedString: testLinkedString.o String.o
	g++ -g testLinkedString.o String.o -o testLinkedString

testLinkedString.o: testLinkedString.cc String.cc String.h
	$(CFLAGS) String.cc testLinkedString.cc

String.o: String.h String.cc
	$(CFLAGS) String.cc

my_shell: my_shell.o
	g++ -g my_shell.o -o my_shell

my_shell.o: my_shell.cc
	$(CFLAGS) my_shell.cc

handle_signals: handle_signals.o
	g++ -g handle_signals.o -o handle_signals

handle_signals.o: handle_signals.cc
	$(CFLAGS) handle_signals.cc

clean:
	rm -rf *.o $(EXEC)

strip:
	strip -s $(EXEC)

print:
	cat String.cc String.h testLinkedString.cc
