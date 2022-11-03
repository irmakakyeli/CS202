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


void insertionSort(int* arr, int size, int& compCount, int& moveCount);
void quickSort(int* arr, int size, int& compCount, int& moveCount);
void mergeSort(int* arr, int size, int& compCount, int& moveCount);
void quickSortRecursive(int* arr, int first, int last, int& compCount, int& moveCount);
void partition(int* arr, int first, int last, int& pivotIndex, int& compCount, int& moveCount);
void mergSortRecursive(int* arr, int first, int last, int size, int& compCount, int& moveCount);
void merge(int* arr, int first, int mid, int last, const int size, int& compCount, int& moveCount);

