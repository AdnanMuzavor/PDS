#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int stack[MAX] = {0};
int top = -1;
int isempty()
{
    if (top == -1)
        return 1;
    return 0;
}
int isfull()
{
    if (top + 1 == MAX)
        return 1;
    return 0;
}
void push(int x)
{
    if (!isfull())
    {
        top++;
        stack[top] = x;
    }
    else
        printf("Stack is full\n");
}
int pop()
{
    if (!isempty())
    {
        int x = stack[top];
        top--;
        return x;
    }
    printf("Stack is empty\n");
    return -1;
}
int peek()
{
    if (!isempty())
        return stack[top];
    else
        printf("Stack is empty\n");
    return -1;
}
void display()
{
    int i = top;
    printf("Elements of stack are: ");
    while (i >= 0)
    {
        printf("%d ", stack[i]);
        i--;
    }
    printf("\n");
}
int main()
{
    int n;
    while (1)
    {
        printf("\nEnter your choice\n");
        printf("1 to push\n2 to pop\n3 to get peek\n4 for display\n5 for exit\nYour choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter element you want to push: ");
            scanf("%d", &n);
            push(n);
            break;
        case 2:
            if (peek() != -1)
                printf("popped element: %d", pop());

            break;
        case 3:
            if (peek() != -1)
                printf("peek element is: %d", peek());
            else
                peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
        default:
            printf("Invalid input\n");
        }
    }

    return 0;
}
