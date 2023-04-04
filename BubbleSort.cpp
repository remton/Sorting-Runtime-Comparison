#include "Sorting.h"

//sorts the array and returns number of data comparisons
int BubbleSort(int* A, const int SIZE) {
    int comps = 0;
    //for the size of the data set
    for (int i = 0; i < (SIZE-1); i++) {
        bool swaped = false;
        //bubble up to i
        for (int j = 0; j < (SIZE-1-i); j++) {
            //compare each item to the one next to it
            comps++;
            if (A[j] > A[j + 1]) {
                swaped = true;
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
        if (!swaped)
            break;
    }
    return comps;
}