// Remington Ward
// CS 4120 Algorithms
//
// The purpose of this project is to compare the runtime of various sorting algorithms:
// Quick sort
// Bubble sort
// Insertion sort
// Heap sort
// 3 way merge sort

// We test these algorithms on random, ascending, and descending data sets of sizes: 1000, 2000, 4000, 8000.
// The data is written into text files

#include <iostream>
#include <iomanip>
#include <chrono>
#include "number_data.h"
#include "Sorting.h"
using namespace std;

void printArr(int* arr, int size);
void Test(const char* name, int (*func)(int*, const int), int size);

int main() {
	//Create our data and write to files
	const int NUM_DATA_SIZES = 4;
	int data_sizes[] = { 1000, 2000, 4000, 8000 };
	//const int NUM_DATA_SIZES = 1;
	//int data_sizes[] = { 10 };
	for (size_t i = 0; i < NUM_DATA_SIZES; i++) {
		int size = data_sizes[i];
		cout << "######################################################" << endl;
		cout << "           " << size << " data elements " << endl;
		cout << "######################################################" << endl;
		write_random_numbers(size);
		write_sorted_numbers(size);
		Test("Quicksort", Quicksort, size); // WORKS
		Test("Bubblesort", BubbleSort, size); // WORKS
		Test("Insertionsort", InsertionSort, size); // WORKS
		Test("Heapsort", HeapSort, size); // WORKS
		Test("3 Way Mergesort", MergeSort3, size); // WORKS
		cout << endl << endl;
	}
}


//couts the int array
void printArr(int* arr, int size) {
	if (size <= 0)
		return;
	cout << "[";
	for (size_t i = 0; i < size - 1; i++) {
		cout << arr[i] << ", ";
	}
	cout << arr[size - 1] << "]" << endl;
}

//Runs the tests on the function pointed to by func
void Test(const char* name, int (*func)(int*, const int), int size) {
	//Initialize our data arrays
	int* rand = new int[size];
	int* asc = new int[size];
	int* des = new int[size];

	//Results in order: [Random, Ascending, Descending]
	int comps[3];
	int time[3];

	//Random
	read_random_numbers(rand, size);
	//printArr(rand, size);
	auto start = chrono::steady_clock::now();
	comps[0] = func(rand, size);
	auto end = chrono::steady_clock::now();
	time[0] = chrono::duration_cast<chrono::microseconds>(end - start).count();
	//printArr(rand, size);

	//Ascending
	read_sorted_numbers(asc, des, size);
	start = chrono::steady_clock::now();
	comps[1] = func(asc, size);
	end = chrono::steady_clock::now();
	time[1] = chrono::duration_cast<chrono::microseconds>(end - start).count();

	//Descending
	start = chrono::steady_clock::now();
	comps[2] = func(des, size);
	end = chrono::steady_clock::now();
	time[2] = chrono::duration_cast<chrono::microseconds>(end - start).count();

	//Print Results
	int SPACING = 15;
	cout << left;
	cout << "======================= " << name << " =======================" << endl;
	cout << setw(SPACING) << "           " << setw(SPACING) << "Random" << setw(SPACING) << "Ascending" << setw(SPACING) << "Descending" << endl;
	cout << setw(SPACING) << "Comparisons" << setw(SPACING) << comps[0] << setw(SPACING) << comps[1] << setw(SPACING) << comps[2] << endl;
	cout << setw(SPACING) << "Microseconds" << setw(SPACING) << time[0] << setw(SPACING) << time[1] << setw(SPACING) << time[2] << endl;
	cout << endl;

	// Clean up
	delete[] rand;
	delete[] asc;
	delete[] des;
}
