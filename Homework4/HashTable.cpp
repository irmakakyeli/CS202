/**
* Author : Irmak Akyeli	
* ID: 21803690
* Section : 2
* Assignment : 4
*/

#include <iostream>
#include <string>
using namespace std;
#include "HashTable.h"


HashTable::HashTable(const int tableSize, const CollisionStrategy goption)
{
	table = new HashNode[tableSize];
	size = tableSize;
	option = goption;
}
 
HashTable::~HashTable()
{
	delete[]table; 

}

bool HashTable::insert(const int item)
{
	int count = 0;
	int index = findIndex(item, false, true, count);
	if (index == -1)
		return false;
	if (table[index].isFull)
		return false; 
	table[index] = HashNode(item);
	table[index].isFree = false;
	table[index].isFull = true;
	return true;
}

bool HashTable::remove(const int item)
{
	int count = 0;
	int index = findIndex(item, true, false, count);
	if (index == -1)
		return false;
	if ((table[index].isFree || table[index].isRemoved))
		return false;
	table[index].isRemoved = true;
	table[index].isFull = false;
	return true;

}

bool HashTable::search(const int item, int& numProbes)
{
	int index = findIndex(item, true, false, numProbes);
	if (table[index].item == item)
		return true;
	return false;
}

void HashTable::display()
{
	for (int i = 0; i < size; i++)
	{
		cout << i << ": ";
		if (table[i].isFree || table[i].isRemoved)
			cout << endl;
		else
			cout << table[i].item << endl;
	}
}

int HashTable::reverseKey(const int key)
{
	int revKey = 0, tempkey = key, digit = 0;
	while (tempkey != 0)
	{
		digit = tempkey % 10;
		revKey = revKey * 10 + digit;
		tempkey /= 10;
	}

	return revKey;
}

void HashTable::analyze(double& numSuccProbes, double& numUnsuccProbes)
{
	int total = 0;
	int probe = 0;
	bool isSuc;
	int count = 0; //how many element in the table
	for (int i = 0; i < size; i++)
	{
		probe = 0;
		if (table[i].isFull)
		{
			count++;
			isSuc = search(table[i].item, probe);
			total = total + probe;
		}
	}
	numSuccProbes = (double)total / (double)count;
	total = 0;
	for (int i = 0; i < size; i++)
	{
		probe = 0;
		int j= i;
		isSuc = search(i, probe);
		while (isSuc)
		{
			j = j + size;
			isSuc = search(j, probe);
		}
		total = total + probe;
	}
	if (option == DOUBLE)
		numUnsuccProbes = - 1;
	else
		numUnsuccProbes = (double)total / (double)size;
}

int HashTable::findIndex(const int item, bool toBeSelected, bool toBeInserted, int & count)
{
	int index = -1;
	if (option == LINEAR)
	{
		count = 1;
		index = item % size;
		if (item < 0)
			index = (size + (item % size)) % size;
		int prevIndex = index;
		while (!table[index].isFree || table[index].isRemoved)
		{
			if (toBeInserted && table[index].isRemoved)
			{
				return index;
			}
			if ((!toBeSelected) && table[index].item == item)
				return -1;
			else if (toBeSelected && table[index].item == item && table[index].isFull)
				return index;
			index++;
			if (index >= size)
				index = 0;
			count++;
			if (index == prevIndex)
				return -1;
		}
		return index;
	}
	else if (option == QUADRATIC)
	{
		index = item % size;
		int indexprev = index;
		if (item < 0)
			index = (size + (item % size)) % size;
		count = 1;
 		while (!table[index].isFree || table[index].isRemoved)
		{
			if (toBeInserted && table[index].isRemoved)
			{
				return index;
			}
			if ((!toBeSelected) && table[index].item == item)
				return -1;
			else if (toBeSelected && table[index].item == item && table[index].isFull)
				return index;
			index = ((indexprev + (count * count)) % size);
			count++; 
			if (count == (size))
				return -1;
		}
		return index;
	}
	else if (option == DOUBLE)
	{
		index = item % size;
		int key = reverseKey(item);
		
		if (item < 0)
			index = (size + (item % size)) % size;
		if (item == 0 || key == 0)
		{
			if (((table[0].isFree || table[0].isRemoved) && !toBeSelected) || (toBeSelected && table[0].item == 0))
				return 0;
			else if (toBeSelected && table[0].item != 0)
				return -1;
		}
		count = 1;
		while (!table[index].isFree || table[index].isRemoved)
		{

			
			if ((!toBeSelected) && table[index].item == item)
				return -1;
			else if (toBeSelected && table[index].item == item && table[index].isFull)
				return index;
			index = ((item % size) + (index * key) % size);
			count++;
			if (count == size)
				return -1;
		}
		return index;
	}
	return -1;
}