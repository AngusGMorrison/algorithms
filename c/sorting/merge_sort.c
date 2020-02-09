#include<stdio.h>

/**
 * Merge sort
 * - O(nlogn)
 * - Divide and conquer algorithm
 * - Outperforms n^2 sorts for all but very small datasets
 * - Requires additional storage for helper array
 * - Stable
**/

void merge_sort(int arr[], size_t size);
void split_merge(int arr[], int i_start, int i_end, int helper[]);
void merge(int arr[], int i_start, int i_mid, int i_end, int helper[]);
void print(int arr[], size_t size);

int main() {
     int arr[] = { 4, 2, 7, 3, 5, 6, 0, 1 };
     size_t size = sizeof(arr) / sizeof(arr[0]);
     merge_sort(arr, size);
     print(arr, size);
}

void merge_sort(int arr[], size_t size)
{
    int helper[size];
    split_merge(arr, 0, size - 1, helper);
}

void split_merge(int arr[], int i_start, int i_end, int helper[])
{
    if (i_end <= i_start)
    {
        return;     // Array size is 1, don't split any further
    }
    int i_mid = (i_end + i_start) / 2;              // Left subarray is arr[i_start..mid]
                                                    // Right subarray is arr[(mid + 1)..i_end]
    split_merge(arr, i_start, i_mid, helper);       // Sort the left subarray recursively
    split_merge(arr, i_mid + 1, i_end, helper);     // Sort the right subarry recursively
    // Merge the sorted subarrays
    merge(arr, i_start, i_mid, i_end, helper);
}

void merge(int arr[], int i_start, int i_mid, int i_end, int helper[])
{
    int i_left_half = i_start;        // Counter to track position in the left subarray
    int i_right_half = i_mid + 1;     // Counter to track position in the right subarray
    
    for (int k = i_start; k <= i_end; k++)   // k represents position in the original array
    {
        /* If there are items in the left half,
           and the right half is empty
           or the current item in the left half is <= the current item in the right half,
           add it to the helper array. */
        if (i_left_half <= i_mid && (i_right_half > i_end || arr[i_left_half] <= arr[i_right_half]))
        {
            helper[k] = arr[i_left_half];
            i_left_half++;
        }
        else
        {
            helper[k] = arr[i_right_half];
            i_right_half++;
        }
    }
    // Copy the sorted helper array to the original
    for (int k = i_start; k <= i_end; k++) {
        arr[k] = helper[k];
    }
}

void print(int arr[], size_t size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}