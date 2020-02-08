#include<stdio.h>

/*
  Selection sort
  - O(n^2)
  - Counterpart to bubble sort
  - Performs poorly in real-world applications
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
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(&arr[j], &arr[i]);
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