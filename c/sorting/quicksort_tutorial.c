#include <stdio.h>
#include <stdlib.h>

/**
 * Quicksort (Hoare partition scheme)
 * - Θ(nlogn)
 * - O(n^2) for already sorted array with pivot as first or last element
 * - Ω(nlogn) for simple partition
 * - Divide and conquer algorithm
 * - In-place
 * - Unstable
 * - Outperforms merge sort for smaller datasets
 * - This version does not implement Sedgwick's method for limiting space complexity to O(logn)
**/

void quick_sort(int arr[], int low, int high, size_t size);
int sort_and_partition(int arr[], int low, int high, size_t size);
void swap(int *first, int *second);
void print(int arr[], size_t size);

int main(void)
{
    int arr[] = { 4, 8, 1, 6, 0, 3, 5, 2};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, 0, size - 1, size);
    print(arr, size);
}

void quick_sort(int arr[], int low, int high, size_t size)
{
    if (low >= high)
    {
        printf("Array has length 1. Return.\n\n");
        return;
    }

    int partition = sort_and_partition(arr, low, high, size);
    // Nothing to the left of partition is greater than the last chosen pivot
    // Nothing to the right of partition is less than the last chosen pivot
    // Sort elements before and after the partition
    printf("Quicksort low = %i to partition = %i\n", low, partition);
    quick_sort(arr, low, partition, size);
    printf("Quicksort partition + 1 = %i to high = %i\n", (partition + 1), high);
    quick_sort(arr, partition + 1, high, size);
}

int sort_and_partition(int arr[], int low, int high, size_t size)
{
    // Pivot is randomly chosen to avoid worst-case runtime
    // when array is already sorted
    int pivot_index = (rand() % (high - low)) + low;
    int pivot = arr[pivot_index];
    printf("Pivot: %i\n", pivot);
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        print(arr, size);
        // Finds the first value from the left greater than
        // or equal to the pivot
        do {
            i++;
        } while (arr[i] < pivot);
        printf("Value %i at index i = %i is >= pivot = %i\n", arr[i], i, pivot);

        // Finds the first value on the right greater than
        // or equal to the pivot
        do {
            j--;
        } while (arr[j] > pivot);
        printf("Value %i at index j = %i is <= pivot = %i\n", arr[j], j, pivot);

        // Return the index at which everything to the left is less than pivot
        // and everything to the right is greater
        if (j <= i)
        {
            printf("Indexed have crossed. New partition j = %i\n\n", j);
            return j;
        }

        // Swaps values greater than the pivot with values less than the pivot
        swap(&arr[i], &arr[j]);
    }
}

void swap(int *first, int *second)
{
    printf("Swapping %i and %i\n\n", *first, *second);
    int temp = *first;
    *first = *second;
    *second = temp;
}

void print(int arr[], size_t size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}