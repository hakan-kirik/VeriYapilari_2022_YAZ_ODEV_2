all: build run


build:
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/Queue.o -c ./src/Queue.cpp
	g++ -I ./include/ -o ./lib/Radix.o -c ./src/Radix.cpp
	g++ -I ./include/ -o ./lib/ReadAndSort.o -c ./src/ReadAndSort.cpp
	g++ -I ./include/ -o ./lib/NodeAVL.o -c ./src/NodeAVL.cpp
	g++ -I ./include/ -o ./lib/Avl.o -c ./src/Avl.cpp

	g++ -I ./include/ -o ./bin/main ./lib/Node.o ./lib/Queue.o ./lib/Radix.o ./lib/ReadAndSort.o ./lib/NodeAVL.o ./lib/Avl.o   ./src/main.cpp

run:
	./bin/main