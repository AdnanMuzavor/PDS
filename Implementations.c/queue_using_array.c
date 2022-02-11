#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int Queue[MAX] = {0};
int front = -1, rear = -1;
int isempty()
{
    if (front == -1 || front == rear)
        return 1;
    return 0;
}
int isfull()
{
    if (rear + 1 == MAX)
        return 1;
    return 0;
}
void enqueue(int x)
{
    if (!isfull())
    {
        if (front == -1)
        {
            front = 0, rear = 0;
        }
        else
            rear++;
        Queue[rear] = x;
    }
    else
        printf("Queue is full\n");
}
int dequeue()
{
    if (!isempty())
    {
        int x = Queue[front];
        front++;
        return x;
    }
    printf("Queue is empty\n");
    return -1;
}
int peek()
{
    if (!isempty())
        return Queue[front];
    else
        printf("Queue is empty\n");
    return -1;
}
void display()
{
    int i = front;
    printf("Elements of Queue are: ");
    while (i <= rear)
    {
        printf("%d ", Queue[i]);
        i++;
    }
    printf("\n");
}
int main()
{
    int n;
    while (1)
    {
        printf("\nEnter your choice\n");
        printf("1 to enqueue\n2 to dequeue\n3 to get peek\n4 for display\n5 for exit\nYour choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter element you want to queue: ");
            scanf("%d", &n);
            enqueue(n);
            break;
        case 2:
            if (peek() != -1)
                printf("dequeueped element: %d", dequeue());

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