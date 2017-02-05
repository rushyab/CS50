/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 * Using Binary Search
 */
bool search(int value, int values[], int n)
{
    int start_index = 0;
    int end_index = n-1;
    
    while (start_index <= end_index) {
        int mid_index = (start_index + end_index) / 2;
        if (value == values[mid_index]) {
            printf("Value Found!");
            return true;
        }
        else if (value < values[mid_index]) {
            end_index = mid_index - 1;
        }
        else {
            start_index = mid_index + 1;
        }
    }

    return false;
}

/**
 * Sorts array of n values using selection sort
 */
void sort(int values[], int n)
{
    // Find smallest element in an unsorted array of size n.
    // Consider first element as smallest.
    for (int i = 0; i < n; i++) {
        int smallest_index = i;
        for (int j = i+1; j < n; j++) {
            if (values[j] < values[smallest_index])
                smallest_index = j;
        }
        // Swap the smallest element with the first element of the unsorted array.
        int temp = values[i];
        values[i] = values[smallest_index];
        values[smallest_index] = temp;
    }
    return;
}
