#include <stdio.h>

#define MAX 100

void merge(int array[], int left, int middle, int right)
{
    int temporary[MAX];
    int i = left;
    int j = middle + 1;
    int k = left;

    while (i <= middle && j <= right)
    {
        if (array[i] <= array[j])
            temporary[k++] = array[i++];
        else
            temporary[k++] = array[j++];
    }

    while (i <= middle)
        temporary[k++] = array[i++];

    while (j <= right)
        temporary[k++] = array[j++];

    for (i = left; i <= right; i++)
        array[i] = temporary[i];
}

void mergeSort(int array[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);
        merge(array, left, middle, right);
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

    printf("LAB TASK 5 - MERGE SORT\n");
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

    mergeSort(array, 0, size - 1);

    printf("Sorted array: ");
    displayArray(array, size);
    return 0;
}