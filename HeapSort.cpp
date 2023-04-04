#include "Sorting.h"

int Build_Max_Heap(int* A, const int SIZE);
int Max_Heapify(int* A, int i, int heapSize);

//sorts the array and returns number of data comparisons
int HeapSort(int* A, const int SIZE) {
	int comps = 0;
	//Build the heap
	comps += Build_Max_Heap(A, SIZE);

	//Sort by calling Max_Heapify on each element
	int heapSize = SIZE;
	for (int i = SIZE-1; i >=0; i--) {
		int temp = A[i];
		A[i] = A[0];
		A[0] = temp;
		heapSize--;
		comps += Max_Heapify(A, 0, heapSize);
	}
	return comps;
}

int parent(int i) { return i / 2; }
int left_child(int i) { return 2 * i; }
int right_child(int i) { return 2 * i + 1; }

int Max_Heapify(int* A, int i, int heapSize) {
	int comps = 0;
	int l = left_child(i);
	int r = right_child(i);
	int largest;
	if (++comps && l < heapSize && A[l] > A[i])
		largest = l;
	else
		largest = i;
	if (++comps && r < heapSize && A[r] > A[largest])
		largest = r;
	if (largest != i) {
		int temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		return Max_Heapify(A, largest, heapSize);
	}
	return comps;
}

int Build_Max_Heap(int* A, const int SIZE) {
	int comps = 0;
	int heapSize = SIZE;
	for (int i = SIZE/2; i >= 0; i--) {
		comps += Max_Heapify(A, i, heapSize);
	}
	return comps;
}