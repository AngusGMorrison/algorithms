#include<stdlib.h>
#include<stdio.h>

/*
  Merge sort
  - O(nlogn)
  - Divide and conquer algorithm
*/

void sort(int arr[], int start_idx, int end_idx);
void merge(int arr[], int start_idx, int mid_idx, int end_idx);
void print(int arr[], size_t size);

int main()
{
    int numbers[] = { 4, 2, 7, 3, 5, 6, 0 };
    size_t size = sizeof(numbers) / sizeof(int);
    sort(numbers, 0, size - 1);
    print(numbers, size);
}

void sort(int arr[], int start_idx, int end_idx)
{
  if (start_idx < end_idx)
  {
    int mid_idx = (start_idx + end_idx) / 2;
    // Recursively sort both halves
    sort(arr, start_idx, mid_idx);
    sort(arr, mid_idx + 1, end_idx);
    // Merge the sorted halves
    merge(arr, start_idx, mid_idx, end_idx);
  }
}

void merge(int arr[], int start_idx, int mid_idx, int end_idx)
{
  // Create temporary arrays for to hold the two havles
  int first_half_len = mid_idx - start_idx + 1;
  int second_half_len = end_idx - mid_idx;

  int first_half[first_half_len], second_half[second_half_len];

  for (int i = 0; i < first_half_len; i++)
  {
    first_half[i] = arr[start_idx + i];
  }

  for (int i = 0; i < second_half_len; i++)
  {
    second_half[i] = arr[mid_idx + 1 + i];
  }

  // Merge the temporary arrays back into the original
  int first_half_idx = 0;
  int second_half_idx = 0;
  int original_arr_idx = start_idx;

  while (first_half_idx < first_half_len && second_half_idx < second_half_len)
  {
    if (first_half[first_half_idx] <= second_half[second_half_idx])
    {
      arr[original_arr_idx] = first_half[first_half_idx];
      first_half_idx++;
    }
    else
    {
      arr[original_arr_idx] = second_half[second_half_idx];
      second_half_idx++;
    }
    original_arr_idx++;
  }

  //Copy any remaining elements of either half
  while (first_half_idx < first_half_len)
  {
    arr[original_arr_idx] = first_half[first_half_idx];
    first_half_idx++;
    original_arr_idx++;
  }

  while (second_half_idx < second_half_len)
  {
    arr[original_arr_idx] = second_half[second_half_idx];
    second_half_idx++;
    original_arr_idx++;
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