#mainSOURCES
MAINS=my_shell.o heroes.o main.o
HEADERS=hero.h
CFLAGS=g++ -g -c
EXEC=my_shell hero

all: $(HEADERS) $(MAINS) $(EXEC)

hero:
	g++ -g heroes.o main.o -o hero

heroes.o: hero.h
	$(CFLAGS) heroes.cc

main.o: hero.h
	$(CFLAGS) main.cc

my_shell: my_shell.o
	g++ -g my_shell.o -o my_shell

my_shell.o: my_shell.cc
	$(CFLAGS) my_shell.cc

clean:
	rm -rf *.o $(EXEC)

strip:
	strip -s my_shell

print:
	cat < my_shell.cc | enscript -p shell.ps
	ps2pdf shell.ps
	rm shell.ps
