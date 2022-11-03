/**
* Author : Irmak Akyeli
* ID: 21803690
* Section : 2
* Assignment : 4
*/

#include <iostream>
#include <string>
using namespace std;

#ifndef HASH_TABLE_H
#define HASH_TABLE_H


class HashTable
{
public:
	enum CollisionStrategy { LINEAR, QUADRATIC, DOUBLE };
	HashTable(const int tableSize, const CollisionStrategy goption);
	~HashTable();
	bool insert(const int item);
	bool remove(const int item);
	bool search(const int item, int& numProbes);
	void display();
	int reverseKey(const int key);
	void analyze(double& numSuccProbes, double& numUnsuccProbes);
	int findIndex(const int item, bool toBeSelected, bool toBeInserted, int & count);
	
	
	class HashNode
	{
	public:
		HashNode()
		{
			item = 0;
			isFree = true;
			isRemoved = false;
			isFull = false;
		}
		HashNode(int gitem)
		{
			item = gitem;
			isFree = true;
			isRemoved = false;
			isFull = false;
		}
		
		int item;
		bool isFree, isRemoved, isFull;
	};

private:
	HashNode* table;
	int size;
	CollisionStrategy option;
	
};

#endif HASH_TABLE_H

