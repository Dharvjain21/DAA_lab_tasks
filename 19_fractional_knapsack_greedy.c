#include <stdio.h>

#define MAX 100

typedef struct
{
    double weight;
    double value;
    double ratio;
} Item;

void sortByRatio(Item items[], int size)
{
    for (int i = 1; i < size; i++)
    {
        Item current = items[i];
        int j = i - 1;

        while (j >= 0 && items[j].ratio < current.ratio)
        {
            items[j + 1] = items[j];
            j--;
        }
        items[j + 1] = current;
    }
}

int main()
{
    Item items[MAX];
    int size;
    double capacity;
    double totalValue = 0.0;
    double remainingCapacity;

    printf("LAB TASK 6 - FRACTIONAL KNAPSACK USING GREEDY APPROACH\n");
    printf("Enter the number of items: ");
    scanf("%d", &size);

    if (size < 1 || size > MAX)
    {
        printf("Invalid number of items.\n");
        return 1;
    }

    printf("Enter knapsack capacity: ");
    scanf("%lf", &capacity);
    if (capacity <= 0)
    {
        printf("Capacity must be positive.\n");
        return 1;
    }

    printf("Enter value and weight for each item:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%lf %lf", &items[i].value, &items[i].weight);
        if (items[i].weight <= 0 || items[i].value < 0)
        {
            printf("Value must be non-negative and weight must be positive.\n");
            return 1;
        }
        items[i].ratio = items[i].value / items[i].weight;
    }

    sortByRatio(items, size);
    remainingCapacity = capacity;

    for (int i = 0; i < size && remainingCapacity > 0; i++)
    {
        double amount = items[i].weight < remainingCapacity
                            ? items[i].weight
                            : remainingCapacity;
        totalValue += amount * items[i].ratio;
        remainingCapacity -= amount;
        printf("Item %d: %.2f weight selected, value gained %.2f\n",
               i + 1, amount, amount * items[i].ratio);
    }

    printf("Maximum value: %.2f\n", totalValue);
    printf("Greedy complexity: O(n log n) time for sorting and O(n) selection.\n");
    printf("Choosing the highest value-to-weight ratio first is optimal when fractions are allowed.\n");
    return 0;
}