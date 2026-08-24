#include <stdio.h>

int main()
{
    int array[100], size, key, low, high, middle, i;

    printf("Enter size of sorted array: ");
    scanf("%d", &size);

    printf("Enter elements in sorted order: ");
    for (i = 0; i < size; i++)
        scanf("%d", &array[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    low = 0;
    high = size - 1;

    while (low <= high)
    {
        middle = (low + high) / 2;

        if (array[middle] == key)
        {
            printf("Element found at position %d", middle + 1);
            return 0;
        }
        else if (key < array[middle])
            high = middle - 1;
        else
            low = middle + 1;
    }

    printf("Element not found");

    return 0;
}
