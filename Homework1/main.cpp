/*
* Title: Algorithm Efficiency and Sorting
* Author: Irmak Akyeli
* ID: 21803690
* Section: 2
* Assignment: 1
* Description: description of your code
*/
#include "auxArrayFunctions.h"
#include "sorting.h"
#include <ctime>
#include <iostream>
#include <string>
using namespace std;


void performanceAnalysis(int size)
{
	int* arr1; //allocate space for variables
	int* arr2;
	int* arr3;
	int compCount;
	int moveCount;


   // createAlreadySortedArrays(arr1, arr2, arr3, size);

    createRandomArrays(arr1, arr2, arr3, size);


	cout << "*************" << endl;
	cout << "Performance Analysis on Unsorted Arrays" << endl;
	cout << "*************" << endl << endl;
	cout << "Array Size\t\tTime Elapsed\t\tcompCount\t\tmoveCount" << endl;
	clock_t time_req;

	/*
	cout << "---------------------------------------" << endl;
	cout << "Performance Analysis of Quick Sort" << endl;
	cout << "---------------------------------------" << endl;
	for (int i = size; i <= 20000; i+=5000)
	{
		time_req = clock();
		quickSort(arr1, i, compCount, moveCount);
		time_req = clock() - time_req;
		cout << i << "\t\t\t" << 10 * 10 * ((float)time_req / (CLOCKS_PER_SEC)) << " ms\t\t\t" << compCount << "\t\t" << moveCount << endl;
	}


	cout << "---------------------------------------" << endl;
	cout << "Performance Analysis of Merge Sort" << endl;
	cout << "---------------------------------------" << endl;

    time_req = clock();
    mergeSort(arr2, 5000, compCount, moveCount);
    time_req = clock() - time_req;
    cout << 5000 << "\t\t\t" << 10 * 10 * ((float)time_req / (CLOCKS_PER_SEC)) << " ms\t\t\t" << compCount << "\t\t" << moveCount << endl;

    time_req = clock();
    mergeSort(arr2, 10000, compCount, moveCount);
    time_req = clock() - time_req;
    cout << 10000 << "\t\t\t" << 10 * 10 * ((float)time_req / (CLOCKS_PER_SEC)) << " ms\t\t\t" << compCount << "\t\t" << moveCount << endl;

    time_req = clock();
    mergeSort(arr2, 15000, compCount, moveCount);
    time_req = clock() - time_req;
    cout << 15000 << "\t\t\t" << 10 * 10 * ((float)time_req / (CLOCKS_PER_SEC)) << " ms\t\t\t" << compCount << "\t\t" << moveCount << endl;

    time_req = clock();
    mergeSort(arr2, 20000, compCount, moveCount);
    time_req = clock() - time_req;
    cout << 20000 << "\t\t\t" << 10 * 10 * ((float)time_req / (CLOCKS_PER_SEC)) << " ms\t\t\t" << compCount << "\t\t" << moveCount << endl;

    time_req = clock();
    mergeSort(arr2, 5000, compCount, moveCount);
    time_req = clock() - time_req;
    cout << 5000 << "\t\t\t" << 10 * 10 * ((float)time_req / (CLOCKS_PER_SEC)) << " ms\t\t\t" << compCount << "\t\t" << moveCount << endl;

    time_req = clock();
    mergeSort(arr2, 25000, compCount, moveCount);
    time_req = clock() - time_req;
    cout << 25000 << "\t\t\t" << 10 * 10 * ((float)time_req / (CLOCKS_PER_SEC)) << " ms\t\t\t" << compCount << "\t\t" << moveCount << endl;

    time_req = clock();
    mergeSort(arr2, 30000, compCount, moveCount);
    time_req = clock() - time_req;
    cout << 30000 << "\t\t\t" << 10 * 10 * ((float)time_req / (CLOCKS_PER_SEC)) << " ms\t\t\t" << compCount << "\t\t" << moveCount << endl;
    */

	cout << "---------------------------------------" << endl;
	cout << "Performance Analysis of Insertion Sort" << endl;
	cout << "---------------------------------------" << endl;
	for (int i = size; i <= 10000; i += 5000)
	{
		time_req = clock();
		insertionSort(arr3, i, compCount, moveCount);
		time_req = clock() - time_req;
		cout << i << "\t\t\t" << 10 * 10 * ((float)time_req / (CLOCKS_PER_SEC)) << " ms\t\t\t" << compCount << "\t\t" << moveCount << endl;
	}

}

int main() {
	//int arr[] = { 9, 5, 8, 15, 16, 6, 3, 11, 18, 0, 14, 17, 2, 9, 11, 7 };
	//int arr1[] = { 9, 5, 8, 15, 16, 6, 3, 11, 18, 0, 14, 17, 2, 9, 11, 7 };
	//int arr2[] = { 9, 5, 8, 15, 16, 6, 3, 11, 18, 0, 14, 17, 2, 9, 11, 7 };
	int compCount;
	int moveCount;

	//cout << "mergesort" << endl;
	//mergeSort(arr, 16, compCount, moveCount);
	//cout << "compCount" << compCount << endl;
	//cout << "moveCount" << moveCount << endl;
	//displayArray(arr, 16);

	//cout << "insertionsort" << endl;
	//insertionSort(arr1, 16, compCount, moveCount);
	//cout << "compCount" << compCount << endl;
	//cout << "moveCount" << moveCount << endl;
	//displayArray(arr1, 16);

	//cout << "quicksort" << endl;
	//quickSort(arr2, 16, compCount, moveCount);
	//cout << "compCount" << compCount << endl;
	//cout << "moveCount" << moveCount << endl;
	//displayArray(arr2, 16);

	performanceAnalysis(5000);


}






