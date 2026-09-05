#include <stdio.h>

#define MAX 100

void swap(int *first, int *second)
{
    int temporary = *first;
    *first = *second;
    *second = temporary;
}

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int smaller = low - 1;

    for (int current = low; current < high; current++)
    {
        if (array[current] <= pivot)
        {
            smaller++;
            swap(&array[smaller], &array[current]);
        }
    }

    swap(&array[smaller + 1], &array[high]);
    return smaller + 1;
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(array, low, high);
        quickSort(array, low, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}

void displayArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main()
{
    int array[MAX];
    int size;

    printf("LAB TASK 5 - QUICK SORT\n");
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    if (size < 1 || size > MAX)
    {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter the elements: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &array[i]);

    quickSort(array, 0, size - 1);

    printf("Sorted array: ");
    displayArray(array, size);
    return 0;
}