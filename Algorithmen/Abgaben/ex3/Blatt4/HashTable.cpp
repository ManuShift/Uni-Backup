#include "HashTable.h"
#include <iostream>

HashTable::HashTable(int _size)
{
	size = _size;
	table = new int[size];
	for (int i = 0; i < size; i++)
	{
		table[i]=0;
	}
	numberOfElements = 0;
}
HashTable::~HashTable()
{
	delete[] table;
}
//calculates the hash value for a given value
int HashTable::hash(int element)
{
	return element%size;
}
//returns the element at a given index
int HashTable::getElement(int index)
{
	return table[index];
}
//inserts an element in the table and updates the number of elements
void HashTable::addElement(int element)
{
	//TODO a)
}

int HashTable::getSize()
{
	return size;
}

bool HashTable::contains(int element)
{
	int index = hash(element);
	for (int i=0; i<size; i++)
	{
		if (table[(index+i)%size]==element)
		{	
 			return true;
		}
		if (table[(index+i)%size]==0)
		{
 			return false;
		}
	}
	return false;
}
