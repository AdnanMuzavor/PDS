#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int l = 0; // to keep track of length
typedef struct node
{
    struct node *next;
    int val;
} node;
node *front = NULL;
node *rear = NULL;
int isempty()
{
    if (front == NULL && rear == NULL)
        return 1;
    return 0;
}
int isfull()
{
    if (l + 1 == MAX)
        return 1;
    return 0;
}
void enqueue(int x)
{
    if (isempty())
    {
        front = rear = (node *)malloc(sizeof(struct node));
        front->val = x;
        front->next = NULL;
        l++;
    }
    else
    {
        if (!isfull())
        {
            node *temp = (node *)malloc(sizeof(node));
            temp->val = x;
            rear->next = temp;
            temp->next = NULL;
            rear = temp;
            l++;
        }
        else
        {
            printf("Queue is full\n");
        }
    }
}
void dequeue()
{
    if (!isempty())
    {
        int x = front->val;
        node *t = front;
        front = front->next;
        free(t);
        l--;
        printf("dequeued value %d ", x);
        return;
    }
    printf("Queue is empty\n");
}
void peek()
{
    if (!isempty())
    {
        printf("peek is: %d", front->val);
        return;
    }
    printf("Queue is empty\n");
}
void display()
{
    if (!isempty())
    {
        printf("\n Queue elememts are: ");
        node *t = front;
        while (t)
        {
            printf("%d ", t->val);
            t = t->next;
        }
        printf("\n");
        return;
    }
    printf("Queue is empty\n");
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
            printf("Enter element you want to enqueue: ");
            scanf("%d", &n);
            enqueue(n);
            break;
        case 2:
            dequeue();
            break;
        case 3:
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
