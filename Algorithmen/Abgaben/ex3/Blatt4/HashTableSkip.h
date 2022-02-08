#include "HashTable.h"
#pragma once
class HashTableSkip : public HashTable
{
	private:
		int garbageLimit;
		int garbageCount;
		//removes the symbols of empty entries
  		void clear();
	public:
		HashTableSkip(int _size, int _garbageLimit) : HashTable(_size)
		{
			garbageLimit=_garbageLimit;		
		}
		//deletes an element,
		void removeElement(int element) override;
};
