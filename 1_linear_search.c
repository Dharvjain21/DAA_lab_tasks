#include <stdio.h>

int main()
{
    int array[100], size, key, i, position = -1;

    printf("Enter size of array: ");
    scanf("%d", &size);

    printf("Enter elements: ");
    for (i = 0; i < size; i++)
        scanf("%d", &array[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    for (i = 0; i < size; i++)
    {
        if (array[i] == key)
        {
            position = i;
            break;
        }
    }

    if (position == -1)
        printf("Element not found");
    else
        printf("Element found at position %d", position + 1);

    return 0;
}
