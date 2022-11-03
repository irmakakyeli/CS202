/**
* Author : Irmak Akyeli
* ID: 21803690
* Section : 2
* Assignment : 3
*/

#include "maxHeap1.h"

// Default constructor 
maxHeap::maxHeap() : size(0) {
	patients = new PatientNode[MAX_HEAP];
}


bool maxHeap::heapIsEmpty() const {
	return (size == 0);
}

void maxHeap::heapInsert(const PatientNode& newItem)
{

	if (size >= MAX_HEAP)
	{
		cout << "HeapException: Heap full" << endl;
		return;
	}

	// Place the new item at the end of the heap
	patients[size] = newItem;

	// Trickle new item up to its proper position
	int place = size;
	int parent = (place - 1) / 2;
	while ((place > 0) && (patients[place].getPriority() > patients[parent].getPriority()))
	{
		PatientNode temp = patients[parent];
		patients[parent] = patients[place];
		patients[place] = temp;

		place = parent;
		parent = (place - 1) / 2;
	}
	++size;
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
		patients[0] = patients[--size];
		heapRebuild(0);
	}
}

void maxHeap::heapRebuild(int root)
{
	int child = 2 * root + 1; 	// index of root's left child, if any
	if (child < size) {
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find larger child
		if ((rightChild < size) && (patients[rightChild].priority > patients[child].priority) ||
			(rightChild < size) && (patients[rightChild].priority == patients[child].priority) && (patients[rightChild].arrivalTime < patients[child].arrivalTime))
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
	for (int i = 0; i < size; i++)
	{
		cout << "patient id: " << patients[i].id << "  patient priority: " << patients[i].priority << "  patient time: " << patients[i].arrivalTime << " " << endl;
	}
}
