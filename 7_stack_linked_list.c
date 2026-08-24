#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push()
{
    struct node *newNode;
    int value;

    newNode = (struct node *)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    temp = top;
    printf("Deleted value: %d\n", top->data);
    top = top->next;
    free(temp);
}

void display()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            push();
        else if (choice == 2)
            pop();
        else if (choice == 3)
            display();
    } while (choice != 4);

    return 0;
}
