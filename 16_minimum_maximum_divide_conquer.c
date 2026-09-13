#include <stdio.h>

#define MAX 100

typedef struct
{
    int minimum;
    int maximum;
} MinMax;

MinMax findMinMax(int array[], int left, int right)
{
    MinMax result;

    if (left == right)
    {
        result.minimum = array[left];
        result.maximum = array[left];
        return result;
    }

    if (right == left + 1)
    {
        if (array[left] < array[right])
        {
            result.minimum = array[left];
            result.maximum = array[right];
        }
        else
        {
            result.minimum = array[right];
            result.maximum = array[left];
        }
        return result;
    }

    int middle = left + (right - left) / 2;
    MinMax firstHalf = findMinMax(array, left, middle);
    MinMax secondHalf = findMinMax(array, middle + 1, right);

    result.minimum = firstHalf.minimum < secondHalf.minimum
                         ? firstHalf.minimum
                         : secondHalf.minimum;
    result.maximum = firstHalf.maximum > secondHalf.maximum
                         ? firstHalf.maximum
                         : secondHalf.maximum;
    return result;
}

int main()
{
    int array[MAX];
    int size;

    printf("LAB TASK 6 - MINIMUM AND MAXIMUM USING DIVIDE AND CONQUER\n");
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

    MinMax result = findMinMax(array, 0, size - 1);
    printf("Minimum element: %d\n", result.minimum);
    printf("Maximum element: %d\n", result.maximum);
    printf("Divide and conquer: O(n) time and O(log n) recursion space.\n");
    printf("It uses fewer comparisons than independently scanning for minimum and maximum.\n");
    return 0;
}