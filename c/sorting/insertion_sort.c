#include<stdio.h>

/*
  Insertion sort
  - O(n^2)
  - Faster than merge sort for very small values of n
  - Limited real-world use
*/

void sort(int arr[], size_t size);
void swap(int* first, int* second);
void print(int arr[], size_t size);

int main()
{
  int numbers[] = { 4, 2, 7, 3, 5, 6, 0 };
  size_t size = sizeof(numbers) / sizeof(int);
  sort(numbers, size);
  print(numbers, size);
}