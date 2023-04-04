#include "Sorting.h"
#include <random>

// Returns the index of the pivot for quicksort
// Sets comps to the number of comparisons
int Partition(int* A, int start, int end, int& comps) {
    comps = 0;

    //Set our pivot to a random value
    int choice = start + rand()%(end-start+1);
    int temp = A[choice];
    A[choice] = A[end];
    A[end] = temp;

    int x = A[end]; // x holds our pivot's value

    // Set i to be the leftmost index
    // i is the index of the last element of the low partition
    // j is the index of the last element of the high partition
    int i = start - 1;
    for (int j = start; j < end; j++) {
        // if the element should be in low partition, make room and put it in 
        comps++;
        if (A[j] <= x) {
            i = i + 1;
            int temp = A[j];
            A[j] = A[i];
            A[i] = temp;
        }
        // if the element should be in the high partition we extend to make room
        // this is represented by the j++ in the for loop.
        // the element is alredy in the right location so we don't need to swap here
    }
    // Swap our pivot with i+1 to be between low and high partitions 
    // i+1 is the index of the leftmost element in high partition
    temp = A[i + 1];
    A[i + 1] = A[end];
    A[end] = temp;
    //return our pivot
    return i + 1;
}


//Quicksorts array A from index p to index r both inclusive
//returns the number of comparisons
int QuicksortRecursive(int* A, int start, int end) {
    int comps = 0;
    if (start < end) {
        int q = Partition(A, start, end, comps);
        comps += QuicksortRecursive(A, start, q - 1);
        comps += QuicksortRecursive(A, q, end);
    }
    return comps;
}

//Quicksorts array A of size SIZE
//returns the number of comparisons
int Quicksort(int* A, const int SIZE) {
    return QuicksortRecursive(A, 0, SIZE-1);
}

