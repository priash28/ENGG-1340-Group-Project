item.o: item.h item.cpp
	g++ -c item.cpp

main.o: main.cpp item.o
	g++ -c main.cpp

final: main.o item.o
	g++ -o final main.o item.o
