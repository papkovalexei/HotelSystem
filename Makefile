LD_FLAGS=-lPocoNet -lPocoUtil -lPocoFoundation

all: server

server: main.o ServerApp.o
	g++ main.o ServerApp.o -o server $(LD_FLAGS)

main.o: main.cpp ServerApp.h
	g++ -c main.cpp $(LD_FLAGS)

ServerApp.o: ServerApp.cpp
	g++ -c ServerApp.cpp $(LD_FLAGS)

clean:
	rm -rf *.o server