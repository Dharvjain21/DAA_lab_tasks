#include <stdio.h>

int main()
{
    int array[100], size, k, i, j, temp;

    printf("Enter size of array: ");
    scanf("%d", &size);

    printf("Enter elements: ");
    for (i = 0; i < size; i++)
        scanf("%d", &array[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    if (k >= 1 && k <= size)
        printf("%dth smallest element is %d", k, array[k - 1]);
    else
        printf("Invalid value of k");

    return 0;
}
