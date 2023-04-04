#include "Sorting.h"

//sorts the array and returns number of data comparisons
int InsertionSort(int* A, const int SIZE) {
    int comps = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = i; j > 0; j--) {
            comps++;
            if (A[j] < A[j - 1]) {
                int temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
            }
            else {
                break;
            }
        }
    }
    return comps;
}