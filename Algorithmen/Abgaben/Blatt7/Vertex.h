#include <string>

using namespace std;

#pragma once
// Klasse zur Speicherung der Knoten mit einem Label pro Knoten
class Vertex 
{
    private:
    	string label;
    
    public:
		/**
		*
		* @return Gibt das Label des Knotens zurück
		*/
    	string getLabel();
    	/**
		*
		* @return Ein Knoten mit dem Label _label
		*/
		Vertex (string _label);
};
