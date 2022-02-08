#include "HashTable.h"
#pragma once
class HashTableShift : public HashTable
{
	public:
		HashTableShift(int _size) : HashTable(_size){}
		//deletes an element,
		void removeElement(int element) override;
};
