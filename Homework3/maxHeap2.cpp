/**
* Author : Irmak Akyeli
* ID: 21803690
* Section : 2
* Assignment : 3
*/

#include "maxHeap2.h"

maxHeap::maxHeap() {
	arraySize = 0;
	size = 10;
	patients = new PatientNode[size];
}


bool maxHeap::heapIsEmpty() const {
	return (arraySize == 0);
}

void maxHeap::heapInsert(const PatientNode& newItem)
{
	if (arraySize >= size)
	{
		if (size == 0)
		{
			size++;
		}
		PatientNode * temp = new PatientNode[size * 2];
		for (int i = 0; i < arraySize; i++)
		{
			temp[i] = patients[i];
		}
		size = size * 2;
		delete[] patients;
		patients = new PatientNode[size];

		for (int i = 0; i < arraySize; i++)
		{
			patients[i] = temp[i];
		}
		delete[] temp;
	}

	patients[arraySize] = newItem;
	// Trickle new item up to its proper position
	int place = arraySize;
	int parent = (place - 1) / 2;
	while ((place > 0) && (patients[place].priority > patients[parent].priority))
	{
		PatientNode temp = patients[parent];
		patients[parent] = patients[place];
		patients[place] = temp;

		place = parent;
		parent = (place - 1) / 2;
	}
	++arraySize;
}


void maxHeap::heapDelete(PatientNode& rootItem)
{
	if (heapIsEmpty())
	{
		cout << "HeapException: Heap empty" << endl;
		return;
	}
	else {
		rootItem = patients[0];
		patients[0] = patients[--arraySize];
		if (arraySize <= size / 2)
		{
			PatientNode* temp = new PatientNode[size / 2];
			for (int i = 0; i < arraySize; i++)
			{
				temp[i] = patients[i];
			}
			size = size / 2;
			delete[] patients;
			patients = new PatientNode[size];

			for (int i = 0; i < arraySize; i++)
			{
				patients[i] = temp[i];
			}
			delete[] temp;
		}
		heapRebuild(0);
	}
	

}

void maxHeap::heapRebuild(int root)
{
	int child = 2 * root + 1; 	// index of root's left child, if any
	if (child < arraySize) {
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find larger child
		if (((rightChild < arraySize) && (patients[rightChild].priority > patients[child].priority)) ||
			((rightChild < arraySize) && (patients[rightChild].priority == patients[child].priority) && (patients[rightChild].arrivalTime < patients[child].arrivalTime)))
			child = rightChild; 	// index of larger child

		// If root’s item is smaller than larger child, swap values
		if ((patients[root].priority < patients[child].priority) || (patients[root].priority == patients[child].priority) && (patients[root].arrivalTime > patients[child].arrivalTime))
		{
			PatientNode temp = patients[root];
			patients[root] = patients[child];
			patients[child] = temp;

			// transform the new subtree into a heap
			heapRebuild(child);
		}
	}
}

void maxHeap::display()
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << "patient id: " << patients[i].id << "  patient priority: " << patients[i].priority << "  patient time: " << patients[i].arrivalTime << " " << endl;
	}
}
