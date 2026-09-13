#include <stdio.h>

#define MAX 100

typedef struct
{
    int sum;
    int left;
    int right;
} Subarray;

Subarray bestCrossingSubarray(int array[], int left, int middle, int right)
{
    int sum = 0;
    int bestLeftSum = array[middle];
    int bestLeft = middle;

    for (int i = middle; i >= left; i--)
    {
        sum += array[i];
        if (sum > bestLeftSum)
        {
            bestLeftSum = sum;
            bestLeft = i;
        }
    }

    sum = 0;
    int bestRightSum = array[middle + 1];
    int bestRight = middle + 1;

    for (int i = middle + 1; i <= right; i++)
    {
        sum += array[i];
        if (sum > bestRightSum)
        {
            bestRightSum = sum;
            bestRight = i;
        }
    }

    Subarray result = {bestLeftSum + bestRightSum, bestLeft, bestRight};
    return result;
}

Subarray maximumSubarray(int array[], int left, int right)
{
    if (left == right)
    {
        Subarray result = {array[left], left, right};
        return result;
    }

    int middle = left + (right - left) / 2;
    Subarray leftResult = maximumSubarray(array, left, middle);
    Subarray rightResult = maximumSubarray(array, middle + 1, right);
    Subarray crossingResult = bestCrossingSubarray(array, left, middle, right);

    if (leftResult.sum >= rightResult.sum && leftResult.sum >= crossingResult.sum)
        return leftResult;
    if (rightResult.sum >= leftResult.sum && rightResult.sum >= crossingResult.sum)
        return rightResult;
    return crossingResult;
}

int main()
{
    int array[MAX];
    int size;

    printf("LAB TASK 6 - MAXIMUM SUBARRAY USING DIVIDE AND CONQUER\n");
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

    Subarray result = maximumSubarray(array, 0, size - 1);
    printf("Maximum subarray: ");
    for (int i = result.left; i <= result.right; i++)
        printf("%d ", array[i]);
    printf("\nMaximum subarray sum: %d\n", result.sum);
    printf("Divide and conquer complexity: O(n log n) time and O(log n) recursion space.\n");
    return 0;
}