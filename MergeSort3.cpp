#include "Sorting.h"
#include <limits.h>
#include <iostream>

int merge(int* A, int start, int index1, int index2, int end);

int MergeSort3Recursive(int* A, int start, int end) {
    int comps = 0;

    int size = end - start;
    if (size > 1) {
        // Compute the breakpoint indexes of the subarrays.
        int split1 = start + (size / 3);
        int split2 = start + (2* size / 3);

        // Recursivly sort each part
        comps += MergeSort3Recursive(A, start, split1);
        comps += MergeSort3Recursive(A, split1, split2); 
        comps += MergeSort3Recursive(A, split2, end); 

        // Merge the three sorted parts.
        comps += merge(A, start, split1, split2, end);
    }
    return comps;
}

// Merge sort using 3 subdivisions
// Sorts the array and returns number of data comparisons
int MergeSort3(int* A, const int SIZE) {
    return MergeSort3Recursive(A, 0, SIZE);
}

// Merges the 3 subarrays divided by index1 and index2 
int merge(int* A, int start, int split1, int split2, int end) {
    int comps = 0;

    int* temp_arr = new int[end - start];

    //Create variables for the start index of each subarray
    int index1 = start;
    int index2 = split1;
    int index3 = split2;

    //Get sizes of each subarray
    int size1 = split1 - start;
    int size2 = split2 - split1;
    int size3 = end - split2;

    //Track how many elements weve used from each subarray.
    int used1 = 0;
    int used2 = 0;
    int used3 = 0;


    for (size_t i = 0; i < end - start; i++) {
        int smallestIndex = -1;
        int smallestVal = INT_MAX;

        // If there is an element in first subarray
        comps++;
        if (used1 < size1) {
            if (A[index1 + used1] < smallestVal) {
                smallestIndex = index1 + used1;
                smallestVal = A[index1 + used1];
            }
        }
        // If there is an element in second subarray
        comps++;
        if (used2 < size2) {
            if (A[index2 + used2] < smallestVal) {
                smallestIndex = index2 + used2;
                smallestVal = A[index2 + used2];
            }
        }
        // If there is an element in third subarray
        comps++;
        if (used3 < size3) {
            if (A[index3 + used3] < smallestVal) {
                smallestIndex = index3 + used3;
                smallestVal = A[index3 + used3];
            }
        }

        // Find which subarray was used and update its values
        if (index1 <= smallestIndex && smallestIndex < (index1 + size1)) {
            used1++;
        }
        else if (index2 <= smallestIndex && smallestIndex < (index2 + size2)) {
            used2++;
        }
        else if (index3 <= smallestIndex && smallestIndex < (index3 + size3)) {
            used3++;
        }
        else {
            std::cout << "ERROR in MergeSort3 merge. no smallest value found" << std::endl;
        }
        temp_arr[i] = smallestVal;
        int x = temp_arr[i];
    }

    //copy temp_arr to A
    for (size_t i = 0; i < end-start; i++) {
        A[start + i] = temp_arr[i];
    }

    delete[] temp_arr;
    return comps;
}