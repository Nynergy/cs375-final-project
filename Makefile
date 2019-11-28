<<<<<<< HEAD
BIN= final
DENSE= dense
SPARSE= sparse
CFLAGS= -std=c++14 -g

all: $(BIN)

$(BIN): main.o DenseGraphTest.o SparseGraphTest.o MatrixGraph.o ListGraph.o Astar.o Dijkstra.o
	g++ $(CFLAGS) main.o MatrixGraph.o Astar.o Dijkstra.o ListGraph.o -o $(BIN)
	g++ $(CFLAGS) DenseGraphTest.o MatrixGraph.o Astar.o Dijkstra.o -o $(DENSE)
	g++ $(CFLAGS) SparseGraphTest.o MatrixGraph.o Astar.o Dijkstra.o -o $(SPARSE)

main.o: main.cpp
	g++ $(CFLAGS) main.cpp -c

MatrixGraph.o: MatrixGraph.cpp MatrixGraph.h Node.h
	g++ $(CFLAGS) MatrixGraph.cpp -c

ListGraph.o: ListGraph.cpp ListGraph.h ListNode.h AdjList.h
	g++ $(CFLAGS) ListGraph.cpp -c

SparseGraphTest.o: SparseGraphTest.cpp
	g++ $(CFLAGS) SparseGraphTest.cpp -c

DenseGraphTest.o: DenseGraphTest.cpp
	g++ $(CFLAGS) DenseGraphTest.cpp -c

Astar.o: Astar.cpp Astar.h
	g++ $(CFLAGS) Astar.cpp -c

Dijkstra.o: Dijkstra.cpp Dijkstra.h
	g++ $(CFLAGS) Dijkstra.cpp -c

run: all
	./$(BIN)
	./$(DENSE)
	./$(SPARSE)

memcheck: all
	valgrind ./$(BIN) -v

clean:
	rm -rf *.o
	rm -rf $(BIN)
	rm -rf $(DENSE)
	rm -rf $(SPARSE)
