#include "Graph.h"

using namespace std;

/**
* Gibt die id des Knotens zurück oder -1 wenn dieser gelöscht wurde.
* Existiert der Knoten ist die id eindeutig und zwischen 0 und n
* @param u der gefragte Knoten
* @return id des Knotens zwischen 0 und n oder -1
*/
int Graph::getId(Vertex* u)
{
    if (!isDeletedVertex[idByVertex[u]])
    	    return idByVertex[u];
    else
	    return -1;
}

/**
* Gibt das Knotenobjekt mit der entsprechenden id zurück
* @param id die gesuchte id
* @return Knotenobjekt mit entsprechender id
*/
Vertex* Graph::getVertex(int id)
{
    return vertexById[id];
}

/**
* Konstruktor für einen Graphen, die Größe wird durch die Größe der Sammlung vertices bestimmt und fixiert.
* @param vertices Eine Sammlung an Knotenelementen
*/
Graph::Graph(list<Vertex*> _vertices) 
{
	vertexById = new Vertex*[_vertices.size()];
	int id = 0;
	for (Vertex* v : _vertices)
	{
		vertices.push_back(v);
		idByVertex[v] = id;
		vertexById[id] = v;
		id++;
	}
	isDeletedVertex = new bool[idByVertex.size()];
	for (int i = 0; i < idByVertex.size(); i++)
	{
		isDeletedVertex[i] = false;
	}
	// Erstellung der Arrays
	n = getVertices().size();
	edges=new list<Vertex*>[n];
}

/**
* Destruktor
*/
Graph::~Graph()
{
	delete[] vertexById;
	delete[] edges;
	delete[] isDeletedVertex;
}
    

/**
* Fügt dem Graphen eine Kante hinzu
* @param u entspricht einen Endpunkt der Kante
* @param v entspricht dem anderen Endpunkt der Kante
*/
void Graph::addEdge(Vertex* u, Vertex* v) 
{
	int uID = getId(u);
	int vID = getId(v);
	if (uID != -1 && vID != -1)
	{
		edges[uID].push_back(v);
		edges[vID].push_back(u);
	}
}

/**
 * Entfernt eine Kante aus dem Graphen, falls vorhanden
 * @param u entspricht einem Endpunkt der Kante
 * @param v entspricht dem anderen Endpunkt der Kante
 */
void Graph::removeEdge(Vertex* u, Vertex* v) 
{
	int uID = getId(u);
	int vID = getId(v);
	if (uID != -1 && vID != -1)
	{
		edges[uID].remove(v);
		edges[vID].remove(u);
	}
}

/**
 * Gibt alle Knoten zurück zu denen u eine Kante besitzt, also die Nachbarschaft von u
 * @param u der Knoten zu welchem die Nachbarn zurückgegeben werden
 * @return
 */
list<Vertex*> Graph::getEdges(Vertex* u) 
{
	int uID = getId(u);
	list<Vertex*> res;
	for (Vertex* target : edges[uID])
	{
		res.push_back(target);
	}
	return res;
}

/**
 * Entfernt alle Kanten eines Knotens und verbirgt ihn im Graphen
 * @param u der zu entfernende Knoten
 */
void Graph::removeVertex(Vertex* u)
{
	// Entferne alle inzidenten Kanten
	for (Vertex* v : getEdges(u))
	{
		removeEdge(v,u);
	}
	// Markiere Knoten als gelöscht
	isDeletedVertex[getId(u)] = true;
}

/**
 * Gibt alle Knoten des Graphen zurück
 * @return Knotenmenge aller Knoten
 */
list<Vertex*> Graph::getVertices()
{
	list<Vertex*> res;
	for (Vertex* v : vertices)
	{
		if (!isDeletedVertex[idByVertex[v]])
		{
			res.push_back(v);
		}
	}
	return res;
}

/**
 * Gibt die Anzahl der Knoten des Graphen zurück
 * @return Anzahl der Knoten
 */
int Graph::getN()
{
	return n;
}   