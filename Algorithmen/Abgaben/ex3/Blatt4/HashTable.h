#pragma once
class HashTable 
{
	protected:
    		int size;
    		int numberOfElements;
    		int* table;
    	public: 
    		HashTable(int _size);
        	~HashTable();
		//calculates the hash value for a given value
   		int hash(int element);
    	//returns the element at a given index
    	int getElement(int index);
    	//deletes an element
	    virtual void removeElement(int element) = 0;
		//inserts an element
    	void addElement(int element);
    	//checks if an element is in the hash table
    	bool contains(int element);
    	int getSize();
};

    

    

    
