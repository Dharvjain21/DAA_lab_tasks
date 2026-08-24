#include <stdio.h>

struct stack
{
    int disk[64];
    int top;
};

void recursiveHanoi(int number, char source, char auxiliary, char destination)
{
    if (number == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    recursiveHanoi(number - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", number, source, destination);
    recursiveHanoi(number - 1, auxiliary, source, destination);
}

void push(struct stack *rod, int disk)
{
    rod->disk[++rod->top] = disk;
}

int pop(struct stack *rod)
{
    if (rod->top == -1)
        return 0;

    return rod->disk[rod->top--];
}

void moveDisk(struct stack *from, struct stack *to, char fromName, char toName)
{
    int first, second;

    first = pop(from);
    second = pop(to);

    if (first == 0)
    {
        push(from, second);
        printf("Move disk %d from %c to %c\n", second, toName, fromName);
    }
    else if (second == 0)
    {
        push(to, first);
        printf("Move disk %d from %c to %c\n", first, fromName, toName);
    }
    else if (first < second)
    {
        push(from, first);
        push(to, second);
        push(to, first);
        printf("Move disk %d from %c to %c\n", first, fromName, toName);
    }
    else
    {
        push(from, first);
        push(from, second);
        push(from, first);
        printf("Move disk %d from %c to %c\n", second, toName, fromName);
    }
}

void iterativeHanoi(int number)
{
    struct stack source, auxiliary, destination;
    long long moves, i;

    source.top = -1;
    auxiliary.top = -1;
    destination.top = -1;

    for (i = number; i >= 1; i--)
        push(&source, i);

    moves = 1;
    for (i = 1; i <= number; i++)
        moves = moves * 2;
    moves = moves - 1;

    if (number % 2 == 0)
    {
        for (i = 1; i <= moves; i++)
        {
            if (i % 3 == 1)
                moveDisk(&source, &auxiliary, 'A', 'B');
            else if (i % 3 == 2)
                moveDisk(&source, &destination, 'A', 'C');
            else
                moveDisk(&auxiliary, &destination, 'B', 'C');
        }
    }
    else
    {
        for (i = 1; i <= moves; i++)
        {
            if (i % 3 == 1)
                moveDisk(&source, &destination, 'A', 'C');
            else if (i % 3 == 2)
                moveDisk(&source, &auxiliary, 'A', 'B');
            else
                moveDisk(&auxiliary, &destination, 'B', 'C');
        }
    }
}

int main()
{
    int number;

    printf("Enter number of disks: ");
    scanf("%d", &number);

    printf("\nRecursive method:\n");
    recursiveHanoi(number, 'A', 'B', 'C');

    printf("\nIterative method:\n");
    iterativeHanoi(number);

    return 0;
}
