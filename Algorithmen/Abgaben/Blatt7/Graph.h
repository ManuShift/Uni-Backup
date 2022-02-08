#include <map>
#include "Vertex.h"
#include <list>

using namespace std;

#pragma once
class Graph
{
    private:
	// Liste der Knoten
	list<Vertex*> vertices;
    	// Array von Listen zur Speicherung der Kanten
	list<Vertex*>* edges;
    	// Map, die jedem Knoten eine ID zuweist
	map<Vertex*,int> idByVertex;
	// Array der Knoten 
    	Vertex** vertexById;
    	// gibt an, ob ein Knoten gelöscht ist
    	bool* isDeletedVertex;
    	int n; 	 

    public:
	Graph(list<Vertex*> _vertices);
	~Graph();
	void addEdge(Vertex* u, Vertex* v);
	void removeEdge(Vertex* u, Vertex* v);
	list<Vertex*> getEdges(Vertex* u);
	void removeVertex(Vertex* u);
	list<Vertex*> getVertices();
	int getN();
	int getId(Vertex* u);
	Vertex* getVertex(int id);
};
