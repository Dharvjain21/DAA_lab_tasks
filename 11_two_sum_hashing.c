#include <stdio.h>
#include <stdlib.h>

int hashFunction(int key, int tableSize)
{
    return key % tableSize;
}

void insert(int *table, int *used, int key, int tableSize)
{
    int index = hashFunction(key, tableSize);
    int i = 0;

    while (used[(index + i) % tableSize] == 1 && table[(index + i) % tableSize] != key)
    {
        i++;
    }

    int pos = (index + i) % tableSize;
    table[pos] = key;
    used[pos] = 1;
}

int search(int *table, int *used, int key, int tableSize)
{
    int index = hashFunction(key, tableSize);
    int i = 0;

    while (used[(index + i) % tableSize] == 1)
    {
        if (table[(index + i) % tableSize] == key)
            return 1;
        i++;
        if (i == tableSize)
            break;
    }

    return 0;
}

int main()
{
    int n, target;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter target value T: ");
    scanf("%d", &target);

    int tableSize = n * 2 + 1;
    int *hashTable = (int *)malloc(tableSize * sizeof(int));
    int *used = (int *)calloc(tableSize, sizeof(int));

    for (int i = 0; i < n; i++)
        insert(hashTable, used, arr[i], tableSize);

    int found = 0;
    for (int i = 0; i < n; i++)
    {
        int complement = target - arr[i];
        if (complement != arr[i] && search(hashTable, used, complement, tableSize))
        {
            printf("Pair found: (%d, %d) -> sum = %d\n", arr[i], complement, target);
            found = 1;
            break;
        }
        else if (complement == arr[i] && search(hashTable, used, arr[i], tableSize))
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[j] == arr[i])
                    count++;
            }
            if (count >= 2)
            {
                printf("Pair found: (%d, %d) -> sum = %d\n", arr[i], arr[i], target);
                found = 1;
                break;
            }
        }
    }

    if (!found)
        printf("No pair exists whose sum is %d\n", target);

    free(arr);
    free(hashTable);
    free(used);
    return 0;
}
