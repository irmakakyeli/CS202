/*
* Title: Algorithm Efficiency and Sorting
* Author: Irmak Akyeli
* ID: 21803690
* Section: 2
* Assignment: 1
* Description: description of your code
*/

#include <string>
using namespace std;
#include "sorting.h"

void insertionSort(int* arr, int size, int& compCount, int& moveCount)
{
	compCount = 0;
	moveCount = 0;
	for (int unsorted = 1; unsorted < size; ++unsorted) {
		int nextItem = arr[unsorted];
		moveCount++;
		int loc = unsorted;

		for (; (loc > 0) && (arr[loc - 1] > nextItem); --loc)
		{
			arr[loc] = arr[loc - 1];
			moveCount++;
		}compCount++;

		arr[loc] = nextItem;
		moveCount;
	}

}
void quickSort(int* arr, int size, int& compCount, int& moveCount)
{
	compCount = 0;
	moveCount = 0;
	quickSortRecursive(arr, 0, size - 1, compCount, moveCount);
}

void quickSortRecursive(int* arr, int first, int last, int& compCount, int& moveCount) {
	// Precondition: theArray[first..last] is an array.
	// Postcondition: theArray[first..last] is sorted.

	int pivotIndex;

	if (first < last) {

		// create the partition: S1, pivot, S2
		partition(arr, first, last, pivotIndex, compCount, moveCount);

		// sort regions S1 and S2
		quickSortRecursive(arr, first, pivotIndex - 1, compCount, moveCount);
		quickSortRecursive(arr, pivotIndex + 1, last, compCount, moveCount);
	}
}

void partition(int* arr, int first, int last, int& pivotIndex, int& compCount, int& moveCount) {
	// Precondition: theArray[first..last] is an array; first <= last.
	// Postcondition: Partitions theArray[first..last] such that:
	//   S1 = theArray[first..pivotIndex-1] < pivot
	//   theArray[pivotIndex] == pivot
	//   S2 = theArray[pivotIndex+1..last] >= pivot

	int* pivot = &arr[first]; // copy pivot
	moveCount++;
		   // initially, everything but pivot is in unknown
	int lastS1 = first;           // index of last item in S1
	int firstUnknown = first + 1; // index of first item in unknown

	 // move one item at a time until unknown region is empty
	for (; firstUnknown <= last; ++firstUnknown) {
		// Invariant: theArray[first+1..lastS1] < pivot
		//            theArray[lastS1+1..firstUnknown-1] >= pivot

		// move item from unknown to proper region
		if (arr[firstUnknown] < *pivot) {  	// belongs to S1
			compCount++;
			++lastS1;
			swap(arr[firstUnknown], arr[lastS1]);
			moveCount += 3;
		}	// else belongs to S2
	}
	// place pivot in proper position and mark its location
	swap(arr[first], arr[lastS1]);
	moveCount += 3;
	pivotIndex = lastS1;
}

void mergeSort(int* arr, int size, int& compCount, int& moveCount)
{
	compCount = 0;
	moveCount = 0;
	mergSortRecursive(arr, 0, size - 1, size, compCount, moveCount);
}

void mergSortRecursive(int* arr, int first, int last, int size, int& compCount, int& moveCount)
{
	if (first < last) {

		int mid = (first + last) / 2; 	// index of midpoint

		mergSortRecursive(arr, first, mid, size, compCount, moveCount);

		mergSortRecursive(arr, mid + 1, last, size, compCount, moveCount);

		// merge the two halves
		merge(arr, first, mid, last, size, compCount, moveCount);
	}

}

void merge(int* arr, int first, int mid, int last, const int size, int& compCount, int& moveCount) {

	int* tempArray = new int[size]; 	// temporary array
	moveCount++;

	int first1 = first; 	// beginning of first subarray
	int last1 = mid; 		// end of first subarray
	int first2 = mid + 1;	// beginning of second subarray
	int last2 = last;		// end of second subarray
	int index = first1; // next available location in tempArray

	for (; (first1 <= last1) && (first2 <= last2); ++index) {
		if (arr[first1] < arr[first2]) {
			compCount++;
			tempArray[index] = arr[first1];
			moveCount++;
			++first1;
		}
		else {
			compCount++;
			tempArray[index] = arr[first2];
			moveCount++;
			++first2;
		}
	}
	// finish off the first subarray, if necessary
	for (; first1 <= last1; ++first1, ++index)
	{
		tempArray[index] = arr[first1];
		moveCount++;
	}

	// finish off the second subarray, if necessary
	for (; first2 <= last2; ++first2, ++index)
	{
		tempArray[index] = arr[first2];
		moveCount++;
	}

	// copy the result back into the original array
	for (index = first; index <= last; ++index)
	{
		arr[index] = tempArray[index];
		moveCount++;
	}
	delete [] tempArray;
}
