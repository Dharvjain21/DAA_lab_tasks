#include <stdio.h>
#include <stdlib.h>

int hashFunction(int key, int tableSize)
{
    return key % tableSize;
}

void insertFrequency(int *table, int *freq, int *used, int key, int tableSize)
{
    int index = hashFunction(key, tableSize);
    int i = 0;

    while (used[(index + i) % tableSize] == 1 && table[(index + i) % tableSize] != key)
    {
        i++;
    }

    int pos = (index + i) % tableSize;
    if (used[pos] == 0)
    {
        table[pos] = key;
        freq[pos] = 1;
        used[pos] = 1;
    }
    else
    {
        freq[pos]++;
    }
}

void displayFrequency(int *table, int *freq, int *used, int tableSize)
{
    printf("Element Frequency:\n");
    for (int i = 0; i < tableSize; i++)
    {
        if (used[i] == 1)
            printf("%d -> %d\n", table[i], freq[i]);
    }
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int tableSize = n * 2 + 1;
    int *hashTable = (int *)malloc(tableSize * sizeof(int));
    int *frequency = (int *)calloc(tableSize, sizeof(int));
    int *used = (int *)calloc(tableSize, sizeof(int));

    for (int i = 0; i < n; i++)
        insertFrequency(hashTable, frequency, used, arr[i], tableSize);

    displayFrequency(hashTable, frequency, used, tableSize);

    free(arr);
    free(hashTable);
    free(frequency);
    free(used);
    return 0;
}
