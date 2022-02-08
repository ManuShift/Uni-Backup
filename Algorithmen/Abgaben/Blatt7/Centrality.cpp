#include "Centrality.h"
#include <queue>

using namespace std;


/**
 *
 * @param g Eingabegraph
 * @param shortestPaths 2-dimensionales nxn-Array in welches die Anzahl (verschiedener) kürzester Pfade
 *                      eingetragen werden sollen, nicht neu initalisieren!
 * @param shortestDistance 2-dimensionales nxn-Array in welches die kürzeste Distanz zwischen eingegeben
 *                         allen Knotenpaaren eingetragen werden sollen, nicht neu initialisieren!
 */
void Centrality::computeShortestPaths(Graph* g, int** shortestPaths, int** shortestDistance)
{
    //TODO: Hier vervollständigen
	return;
}

/**
 * Berechnet die Betweenness-Centrality für alle Knoten des Graphen g
 * @param g Eingabegraph
 * @return Array der Länge n mit der Betweenness-Centrality des Knoten v an Stelle v
 */
double* Centrality::betweennessCentrality(Graph* g)
{   
	int n = g->getN();
	// Initialisiere Arrays für den Aufruf von computeShortestPaths
	double* centralityValue = new double[n];
	int** shortestPaths = new int*[n];
	for(int i = 0; i < n; i++)
	{
		shortestPaths[i] = new int[n];	
		for (int j = 0; j < n; j++)
		{
			shortestPaths[i][j]=0.0;
		}
	}
	int** shortestDistance= new int*[n];
	for(int i = 0; i < n; i++)
	{
		shortestDistance[i] = new int[n];	
		for (int j = 0; j < n; j++)
		{
			shortestDistance[i][j]=0;
		}
	}
	// Berechne die kürzesten Pfade zwischen allen Knoten
	Centrality::computeShortestPaths(g, shortestPaths, shortestDistance);

	for(int i=0; i<n ; i++) //Vertex v
	{
		for(int j=0; j<n ; j++) //Vertex s
		{
			if (i==j) 
				continue;
			for(int k=j+1; k<n ; k++) //Vertex t
			{
				if (i==k) 
					continue;
				// Falls v auf einem kürzesten Pfad von s zu t ist, ist die Anzahl kürzester  Pfade von s zu t über v
				// gleich der Anzahl kürzester Pfade von s nach v mal die Anzahl kürzester Pfade von v nach t.
				if(shortestDistance[j][k] == shortestDistance[j][i]+shortestDistance[i][k])
				{
					double shortestPathsThroughThis = shortestPaths[j][i]*shortestPaths[i][k];
					centralityValue[i] += shortestPathsThroughThis / shortestPaths[j][k];
				}
			}
		}
	}
	// Gebe Speicher frei
	for(int i = 0; i < n; i++)
    		delete[] shortestPaths[i];
	delete[] shortestPaths;
	for(int i = 0; i < n; i++)
    		delete[] shortestDistance[i];
	delete[] shortestDistance;
   	return centralityValue;
}
    
/**
 * Berechnet die Closeness-Centrality für alle Knoten des Graphen g
 * @param g Eingabegraph
 * @return Array der Länge n mit der Closeness-Centrality des Knoten v an Stelle v
 */
double* Centrality::closenessCentrality(Graph* g)
{   
	int n = g->getN();
	double* centralityValue = new double[n];
	for (int i = 0; i < n; i++)
	{
		centralityValue[i]=0.0;
	}
	int** shortestPaths = new int*[n];
	for(int i = 0; i < n; i++)
	{
		shortestPaths[i] = new int[n];	
		for (int j = 0; j < n; j++)
		{
			shortestPaths[i][j]=0;
		}
	}
	int** shortestDistance= new int*[n];
	for(int i = 0; i < n; i++)
	{
		shortestDistance[i] = new int[n];	
		for (int j = 0; j < n; j++)
		{
			shortestDistance[i][j]=0;
		}
	}	
	Centrality::computeShortestPaths(g, shortestPaths, shortestDistance);
	for(int i=0; i<n ; i++)//Vertex v
	{ 
		// Summiere die Länge aller kürzesten Pfade von v
		for(int j=0; j<n ; j++) //Vertex t
		{ 
			if (i==j) 
				continue;
			centralityValue[i]+=shortestDistance[i][j];
		}
		// Bilde den Kehrwert
		centralityValue[i]=1/centralityValue[i];
	}
	for(int i = 0; i < n; i++)
    		delete[] shortestPaths[i];
	delete[] shortestPaths;
	for(int i = 0; i < n; i++)
    		delete[] shortestDistance[i];
	delete[] shortestDistance;
   	return centralityValue;
}
    
/**
 * Berechnet die Graph-Centrality für alle Knoten des Graphen g
 * @param g Eingabegraph
 * @return Array der Länge n mit der Graph-Centrality des Knoten v an Stelle v
 */
double* Centrality::graphCentrality(Graph* g)
{   
	int n = g->getN();
	double* centralityValue = new double[n];
	for (int i = 0; i < n; i++)
	{
		centralityValue[i]=0.0;
	}

	int** shortestPaths = new int*[n];
	for(int i = 0; i < n; i++)
	{
		shortestPaths[i] = new int[n];	
		for (int j = 0; j < n; j++)
		{
			shortestPaths[i][j]=0;
		}
	}
	int** shortestDistance= new int*[n];
	for(int i = 0; i < n; i++)
	{
		shortestDistance[i] = new int[n];	
		for (int j = 0; j < n; j++)
		{
			shortestDistance[i][j]=0;
		}
	}	
	Centrality::computeShortestPaths(g, shortestPaths, shortestDistance);

	for(int i=0; i<n ; i++)//Vertex v
	{ 
		for(int j=0; j<n ; j++) //Vertex t
		{ 
			if (i==j) 
				continue;
			// Falls der Pfad von v zu t länger ist als der bisher längste kürzeste Pfad, merke die Länge
			if (centralityValue[i]<shortestDistance[i][j])
			{
				centralityValue[i]=shortestDistance[i][j];
			}
		}
		// Bilde den Kehrwert
		centralityValue[i]=1/centralityValue[i];
	}
	
	for(int i = 0; i < n; i++)
    		delete[] shortestPaths[i];
	delete[] shortestPaths;
	for(int i = 0; i < n; i++)
    		delete[] shortestDistance[i];
	delete[] shortestDistance;
	return centralityValue;
}
