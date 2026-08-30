#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];
int used[SIZE];

void initializeTable()
{
    for (int i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1;
        used[i] = 0;
    }
}

int hashFunction(int key)
{
    return key % SIZE;
}

void insertLinear(int key)
{
    int index = hashFunction(key);
    int i = 0;

    while (used[(index + i) % SIZE] == 1 && hashTable[(index + i) % SIZE] != key)
    {
        i++;
        if (i == SIZE)
        {
            printf("Hash table is full. Cannot insert %d\n", key);
            return;
        }
    }

    int pos = (index + i) % SIZE;
    hashTable[pos] = key;
    used[pos] = 1;
    printf("Inserted %d at index %d\n", key, pos);
}

int searchLinear(int key)
{
    int index = hashFunction(key);
    int i = 0;

    while (used[(index + i) % SIZE] == 1)
    {
        if (hashTable[(index + i) % SIZE] == key)
            return (index + i) % SIZE;

        i++;
        if (i == SIZE)
            break;
    }

    return -1;
}

void displayTable()
{
    printf("Hash Table contents:\n");
    for (int i = 0; i < SIZE; i++)
    {
        if (used[i])
            printf("Index %d -> %d\n", i, hashTable[i]);
        else
            printf("Index %d -> EMPTY\n", i);
    }
}

int main()
{
    int choice, key, result;

    initializeTable();

    do
    {
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            insertLinear(key);
            break;

        case 2:
            printf("Enter key to search: ");
            scanf("%d", &key);
            result = searchLinear(key);
            if (result == -1)
                printf("Key %d not found\n", key);
            else
                printf("Key %d found at index %d\n", key, result);
            break;

        case 3:
            displayTable();
            break;

        case 4:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
