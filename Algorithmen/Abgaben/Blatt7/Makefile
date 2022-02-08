all: centrality
	make clean;

centrality: Main.o Graph.o Centrality.o Vertex.o
	g++ -o centrality Main.o Graph.o Centrality.o Vertex.o

Main.o:
	g++ -c Main.cpp

Graph.o:
	g++ -c Graph.cpp

Centrality.o:
	g++ -c Centrality.cpp

Vertex.o:
	g++ -c Vertex.cpp

clean:
	rm *.o;
