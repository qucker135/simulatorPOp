#Default compiler is g++
CC = g++
#Default executable filename
EXE = main

all: main.o object.o pierwiastki.o zwiazki.o mikroby.o plansza.o
	$(CC) main.o object.o pierwiastki.o zwiazki.o mikroby.o plansza.o -o $(EXE)

clean:
	rm -f *.o

run:
	./$(EXE)

main.o: main.cpp object.h object.cpp pierwiastki.h pierwiastki.cpp zwiazki.h zwiazki.cpp mikroby.h mikroby.cpp plansza.h plansza.cpp
	$(CC) main.cpp -c -o main.o

object.o: object.h object.cpp
	$(CC) object.cpp -c -o object.o

pierwiaski.o: object.h object.cpp pierwiastki.h pierwiastki.cpp
	$(CC) pierwiastki.cpp -c -o pierwiastki.o

zwiazki.o: object.h object.cpp zwiazki.h zwiazki.cpp
	$(CC) zwiazki.cpp -c -o zwiazki.o

mikroby.o: object.h object.cpp mikroby.h mikroby.cpp
	$(CC) mikroby.cpp -c -o mikroby.o

plansza.o: object.h object.cpp pierwiastki.h pierwiastki.cpp zwiazki.h zwiazki.cpp mikroby.h mikroby.cpp plansza.h plansza.cpp
	$(CC) plansza.cpp -c -o plansza.o
