#include<stdio.h>

/**
  * Insertion sort
  * - Θ(n^2)
  * - O(n^2)
  * - Ω(n)
  * - Stable
  * - Limited real-world use
**/

void sort(int arr[], size_t size);
void print(int arr[], size_t size);

int main()
{
  int numbers[] = { 4, 2, 7, 3, 5, 6, 0 };
  size_t size = sizeof(numbers) / sizeof(int);
  sort(numbers, size);
  print(numbers, size);
}

void sort(int arr[], size_t size)
{
  for (int i = 1; i < size; i++)
  {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
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