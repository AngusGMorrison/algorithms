#include<stdio.h>

/*
  Bubble sort
  - O(n^2)
  - Performs poorly in real-world use
*/

void sort(int arr[], size_t length);
void swap(int* first, int* second);
void print(int arr[], size_t length);

int main()
{
    int numbers[] = { 4, 2, 7, 3, 5, 6, 0 };
    size_t length = sizeof(numbers) / sizeof(int);
    sort(numbers, length);
    print(numbers, length);
}

void sort(int arr[], size_t length)
{
    for (int i = 0; i < (length - 1); i++)
    {
        for (int j = 0; j < (length - i - 1); j++)
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

void print(int arr[], size_t length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}