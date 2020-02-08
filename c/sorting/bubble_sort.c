#include<stdio.h>

/*
  Bubble sort
  - O(n^2)
  - Performs poorly in real-world use
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

void sort(int arr[], size_t size)
{
    for (int i = 0; i < (size - 1); i++)
    {
        for (int j = 0; j < (size - i - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void swap(int* first, int* second)
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