/**
* Author : Irmak Akyeli
* ID: 21803690
* Section : 2
* Assignment : 3
*/

#include "PatientNode.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

#ifndef MAX_HEAP_2_H
#define MAX_HEAP_2_H

class maxHeap
{
public:
	maxHeap();				// default constructor
	// copy constructor and destructor are supplied by the compiler
	bool heapIsEmpty() const;
	void heapInsert(const PatientNode& newItem);
	void heapDelete(PatientNode& rootItem);
	void display();
protected:
	void heapRebuild(int root);		// Converts the semiheap rooted at 
							// index root into a heap
private:
	int size;            	// number of heap items
	int arraySize;
	PatientNode* patients;	// array of heap items
	
};
#endif