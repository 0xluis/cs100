#mainSOURCES
COINS=Coins.h Coins.cc
MAINS=main.o betterMain.o bestMain.o my_ls.o
CFLAGS=g++ -g -c
EXEC=main betterMain bestMain my_ls

all: $(COINS) $(MAINS) $(EXEC)

main: main.o Coins.o
	g++ -g main.o Coins.o -o main

main.o: main.cc $(COINS)
	$(CFLAGS) main.cc Coins.cc

Coins.o: $(COINS)
	$(CFLAGS) Coins.cc

betterMain.o: $(Coins) betterMain.cc
	$(CFLAGS) betterMain.cc Coins.cc

bestMain.o: $(COINS)
	$(CFLAGS) bestMain.cc Coins.cc

betterMain: betterMain.o Coins.o
	g++ -g betterMain.o Coins.o -o betterMain

bestMain: bestMain.o Coins.o
	g++ -g bestMain.o Coins.o -o bestMain

my_ls.o: my_ls.cc
	$(CFLAGS) my_ls.cc

my_ls: my_ls.o
	g++ -g my_ls.o -o my_ls

clean:
	rm -rf *.o $(EXEC)
