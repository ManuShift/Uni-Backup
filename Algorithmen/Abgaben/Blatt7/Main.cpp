#include "Vertex.h"
#include "Graph.h"
#include "Centrality.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	// Erstelle den Graphen aus Aufgabe 3 des Präsenzübungsblatts
	list<Vertex*> vertexList;
	Vertex* v1 = new Vertex("Diddy Kong");
	Vertex* v2 = new Vertex("Donkey Kong");
	Vertex* v3 = new Vertex("Boo");
	Vertex* v4 = new Vertex("Toadette");
	Vertex* v5 = new Vertex("Peach");
	Vertex* v6 = new Vertex("King Boo");
	Vertex* v7 = new Vertex("Luigi");
	Vertex* v8 = new Vertex("Captain Toad");
	Vertex* v9 = new Vertex("Waluigi");
	Vertex* v10 = new Vertex("Bowser");
	Vertex* v11 = new Vertex("Mario");
	Vertex* v12 = new Vertex("Bowser Jr.");
	Vertex* v13 = new Vertex("Goomba");
	Vertex* v14 = new Vertex("Yoshi");
	Vertex* v15 = new Vertex("Wario");
	vertexList.push_back(v1);
	vertexList.push_back(v2);
	vertexList.push_back(v3);
	vertexList.push_back(v4);
	vertexList.push_back(v5);
	vertexList.push_back(v6);
	vertexList.push_back(v7);
	vertexList.push_back(v8);
	vertexList.push_back(v9);
	vertexList.push_back(v10);
	vertexList.push_back(v11);
	vertexList.push_back(v12);
	vertexList.push_back(v13);
	vertexList.push_back(v14);
	vertexList.push_back(v15);
	Graph* g = new Graph(vertexList);
	g->addEdge(v1, v2);
	g->addEdge(v1, v4);
	g->addEdge(v2, v5);
	g->addEdge(v2, v10);
	g->addEdge(v3, v4);
	g->addEdge(v3, v6);
	g->addEdge(v4, v7);
	g->addEdge(v4, v8);
	g->addEdge(v4, v9);
	g->addEdge(v5, v8);
	g->addEdge(v5, v10);
	g->addEdge(v5, v11);
	g->addEdge(v6, v7);
	g->addEdge(v6, v13);
	g->addEdge(v7, v9);
	g->addEdge(v7, v11);
	g->addEdge(v8, v14);
	g->addEdge(v9, v12);
	g->addEdge(v9, v15);
	g->addEdge(v10, v11);
	g->addEdge(v10, v12);
	g->addEdge(v11, v13);
	g->addEdge(v11, v14);
	g->addEdge(v12, v15);
	g->addEdge(v14, v15);

	// Berechnet die Zentralitätsmaße
	double* gCentrality = Centrality::graphCentrality(g);
	double* cCentrality = Centrality::closenessCentrality(g);
	double* bCentrality = Centrality::betweennessCentrality(g);

	cout << "Knoten:\tGraph-Zentralität:\tCloseness-Zentralität:\tBetweenness-Zentralität:" << endl;
	double max = 0;
	Vertex* vMax = nullptr;
	for(Vertex* v : vertexList)
	{
		cout << v->getLabel() << ":\t" << gCentrality[g->getId(v)] << "\t" << cCentrality[g->getId(v)] << "\t" << bCentrality[g->getId(v)] << endl;
		if (bCentrality[g->getId(v)]>max)
		{
			vMax = v;
			max = bCentrality[g->getId(v)];
		}
	}
	cout << "\nZentralster Knoten: "<< vMax->getLabel() <<  " mit Zentralität: "<< max << endl;
	delete[] gCentrality;
	delete[] cCentrality;
	delete[] bCentrality;
	delete v1;
	delete v2;
	delete v3;
	delete v4;
	delete v5;
	delete v6;
	delete v7;
	delete v8;
	delete v9;
	delete v10;
	delete v11;
	delete v12;
	delete v13;
	delete v14;
	delete v15;
	delete g;
	printf("Hallo\n");
		printf("Hallo\n");
			printf("Hallo\n");
}
