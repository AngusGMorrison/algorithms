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

void quicksort(int arr[], int low, int high);
int sort_and_partition(int arr[], int low, int high);
void swap(int *first, int *second);
void print(int arr[], size_t size);

int main(void)
{
    int arr[] = { 4, 8, 1, 6, 0, 3, 5, 2};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, size - 1);
    print(arr, size);
}

void quicksort(int arr[], int low, int high)
{
    if (low >= high) return;

    int partition = sort_and_partition(arr, low, high);
    // Nothing to the left of partition is greater than the last chosen pivot
    // Nothing to the right of partition is less than the last chosen pivot
    // Sort elements before and after the partition
    quicksort(arr, low, partition);
    quicksort(arr, partition + 1, high);
}

int sort_and_partition(int arr[], int low, int high)
{
    // Pivot is randomly chosen to avoid worst-case runtime
    // when array is already sorted
    int pivot_index = (rand() % (high - low)) + low;
    int pivot = arr[pivot_index];
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        // Finds the first value from the left greater than
        // or equal to the pivot
        do {
            i++;
        } while (arr[i] < pivot);

        // Finds the first value on the right greater than
        // or equal to the pivot
        do {
            j--;
        } while (arr[j] > pivot);

        // Return the index at which everything to the left is less than pivot
        // and everything to the right is greater
        if (j <= i) return j;

        // Swaps values greater than the pivot with values less than the pivot
        swap(&arr[i], &arr[j]);
    }
}

void swap(int *first, int *second)
{
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