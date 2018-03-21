assign4:	bats.o gold.o pits.o wumpus.o no_event.o room.o cave.o main.o
	g++ -g bats.o gold.o pits.o wumpus.o no_event.o room.o cave.o main.o -o assign4

bats.o:	bats.cpp
	g++ -g -c bats.cpp

gold.o:	gold.cpp
	g++ -g -c gold.cpp

pits.o:	pits.cpp
	g++ -g -c pits.cpp

wumpus.o:	wumpus.cpp
	g++ -g -c wumpus.cpp
no_event.o:	no_event.cpp
	g++ -g -c no_event.cpp

room.o:	room.cpp
	g++ -g -c room.cpp

cave.o:	cave.cpp
	g++ -g -c cave.cpp #-D DEBUG

main.o:	main.cpp
	g++ -g -c main.cpp

clean:
	rm -f *.o assign4
