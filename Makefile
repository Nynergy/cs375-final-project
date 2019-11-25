BIN=final
CFLAGS= -std=c++14 -g

all: $(BIN)

$(BIN): main.o MatrixGraph.o Astar.o
	g++ $(CFLAGS) main.o MatrixGraph.o Astar.o -o $(BIN)

main.o: main.cpp
	g++ $(CFLAGS) main.cpp -c

MatrixGraph.o: MatrixGraph.cpp MatrixGraph.h Node.h
	g++ $(CFLAGS) MatrixGraph.cpp -c

Astar.o: Astar.cpp Astar.h
	g++ $(CFLAGS) Astar.cpp -c

run: all
	./$(BIN)

memcheck: all
	valgrind ./$(BIN) -v

clean:
	rm -rf *.o
	rm -rf $(BIN)
