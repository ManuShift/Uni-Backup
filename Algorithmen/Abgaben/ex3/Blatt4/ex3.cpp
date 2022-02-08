#include "HashTableSkip.h"
#include "HashTableShift.h"
#include <stdlib.h>
#include <time.h>      
#include <iostream>      


using namespace std;

void createRandomElements(int* elements, bool* elementsToDelete, int n, int seed)
{
    srand(seed);
	// Create a random list of integers and a random decision if it will be deleted later on or not 
	for (int i = 0; i < n; i++)
	{
		bool newElementNeeded = true;
		int newElement;
		while (newElementNeeded)
		{
			newElement = rand() % 100000 + 1;
			newElementNeeded=false;
			for (int j = 0; j < i; j++)
			{
				if (elements[j] == newElement)
				{
					newElementNeeded=true;
				}	
			}
		}
	    elements[i] = newElement;
	    elementsToDelete[i] = rand() > (RAND_MAX / 2);
	}
}

void addElements(HashTable& ht, int* elements, int n)
{
    for (int i = 0; i < n; i ++)
	{
		ht.addElement(elements[i]);
	}
}

void removeElements(HashTable& ht, int* elements, bool* elementsToDelete, int n)
{
    for (int i = 0; i < n; i++)
	{
		if (elementsToDelete[i])
		{
			ht.removeElement(elements[i]);
		}
	}
}

bool checkElements(HashTable& ht, int* elements, bool* elementsToDelete, int n)
{
    bool ok = true;
    for (int i = 0; i < n; i++)
	{
		if ((elementsToDelete[i] && ht.contains(elements[i])) || (!elementsToDelete[i] && !ht.contains(elements[i])))
		{
			cerr << "Fehler bei " << elements[i] << "!" << endl;
            ok = false;
		}
	}
    return ok;
}

void printHashTable(HashTable& ht)
{
    for (int i = 0; i < ht.getSize(); i++)
	{
		cout << i << ":\t" << ht.getElement(i) << endl; 
	}
}

int main (int argc, char** argv)
{
	int n = 1024*32;
	int size = 2*n;
	int elements[n];
	bool elementsToDelete[n];
    createRandomElements(elements, elementsToDelete,n, 1234567890);	
	
    HashTableSkip ht1 = HashTableSkip(size,size/8);
    addElements(ht1,elements,n);
	//printHashTable(ht1);
    removeElements(ht1,elements,elementsToDelete,n);
	//printHashTable(ht1);
    if (checkElements(ht1,elements,elementsToDelete,n))
    {
        cout << "HashTableSkip funktioniert!" << endl;
    }
    else
    {
        cout << "HashTableSkip funktioniert nicht!" << endl;
    }

    HashTableShift ht2 = HashTableShift(size);
    addElements(ht2,elements,n);
	//printHashTable(ht2);
    removeElements(ht2,elements,elementsToDelete,n);
	//printHashTable(ht2);
    if (checkElements(ht2,elements,elementsToDelete,n))
    {
        cout << "HashTableShift funktioniert!" << endl;
    }
    else
    {
        cout << "HashTableShift funktioniert nicht!" << endl;
    }
    return 0;
}
