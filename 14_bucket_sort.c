#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void insertionSort(int bucket[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int value = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > value)
        {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = value;
    }
}

int bucketSort(int array[], int size)
{
    int maximum = array[0];
    int bucketCount = size;
    int **buckets = malloc(bucketCount * sizeof(*buckets));
    int *bucketSizes = calloc(bucketCount, sizeof(*bucketSizes));

    if (buckets == NULL || bucketSizes == NULL)
    {
        free(buckets);
        free(bucketSizes);
        return 0;
    }

    for (int i = 1; i < size; i++)
        if (array[i] > maximum)
            maximum = array[i];

    for (int i = 0; i < bucketCount; i++)
    {
        buckets[i] = malloc(size * sizeof(**buckets));
        if (buckets[i] == NULL)
        {
            for (int j = 0; j < i; j++)
                free(buckets[j]);
            free(buckets);
            free(bucketSizes);
            return 0;
        }
    }

    for (int i = 0; i < size; i++)
    {
        int index = (maximum == 0) ? 0 : (long long)array[i] * bucketCount / (maximum + 1LL);
        buckets[index][bucketSizes[index]++] = array[i];
    }

    int position = 0;
    for (int i = 0; i < bucketCount; i++)
    {
        insertionSort(buckets[i], bucketSizes[i]);
        for (int j = 0; j < bucketSizes[i]; j++)
            array[position++] = buckets[i][j];
        free(buckets[i]);
    }

    free(buckets);
    free(bucketSizes);
    return 1;
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

    printf("LAB TASK 5 - BUCKET SORT\n");
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    if (size < 1 || size > MAX)
    {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter non-negative elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
        if (array[i] < 0)
        {
            printf("Bucket sort requires non-negative elements.\n");
            return 1;
        }
    }

    if (!bucketSort(array, size))
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Sorted array: ");
    displayArray(array, size);
    return 0;
}