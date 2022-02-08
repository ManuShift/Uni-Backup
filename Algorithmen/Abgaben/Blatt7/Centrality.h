#include "Graph.h"
#include "Vertex.h"

#pragma once
namespace Centrality
{
	/**
	* Berechnet die Betweenness-Centrality für alle Knoten des Graphen g
	* @param g Eingabegraph
	* @return Array der Länge n mit der Betweenness-Centrality des Knoten v an Stelle v
	*/
    double* betweennessCentrality(Graph* g);
    
    /**
    * Berechnet die Closeness-Centrality für alle Knoten des Graphen g
    * @param g Eingabegraph
    * @return Array der Länge n mit der Betweenness-Centrality des Knoten v an Stelle v
    */
    double* closenessCentrality(Graph* g);
    
    /**
    * Berechnet die Graph-Centrality für alle Knoten des Graphen g
    * @param g Eingabegraph
    * @return Array der Länge n mit der Betweenness-Centrality des Knoten v an Stelle v
    */
    double* graphCentrality(Graph* g);
    
    /**
    *
    * @param g Eingabegraph
    * @param shortestPaths 2-dimensionales nxn-Array in welches die Anzahl (verschiedener) kürzester Pfade
    *                      eingetragen werden sollen, nicht neu initalisieren!
    * @param shortestDistance 2-dimensionales nxn-Array in welches die kürzeste Distanz zwischen eingegeben
    *                         allen Knotenpaaren eingetragen werden sollen, nicht neu initialisieren!
    */
    void computeShortestPaths(Graph* g, int** shortestPaths, int** shortestDistance);
};
