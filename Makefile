BIN=final
CFLAGS= -std=c++14 -g

all: $(BIN)

$(BIN): main.o MatrixGraph.o Astar.o Dijkstra.o ListGraph.o
	g++ $(CFLAGS) main.o MatrixGraph.o Astar.o Dijkstra.o ListGraph.o -o $(BIN)

main.o: main.cpp
	g++ $(CFLAGS) main.cpp -c

MatrixGraph.o: MatrixGraph.cpp MatrixGraph.h Node.h
	g++ $(CFLAGS) MatrixGraph.cpp -c

ListGraph.o: ListGraph.cpp ListGraph.h ListNode.h AdjList.h
	g++ $(CFLAGS) ListGraph.cpp -c
	
Astar.o: Astar.cpp Astar.h
	g++ $(CFLAGS) Astar.cpp -c

Dijkstra.o: Dijkstra.cpp Dijkstra.h
	g++ $(CFLAGS) Dijkstra.cpp -c

run: all
	./$(BIN)

memcheck: all
	valgrind ./$(BIN) -v

clean:
	rm -rf *.o
	rm -rf $(BIN)
