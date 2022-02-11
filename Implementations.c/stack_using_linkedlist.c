#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int l = 0; // to keep track of length
typedef struct node
{
    struct node *next;
    int val;
} node;
node *top = NULL;
int isempty()
{
    if (top == NULL)
        return 1;
    return 0;
}
int isfull()
{
    if (l + 1 == MAX)
        return 1;
    return 0;
}
void push(int x)
{
    if (isempty())
    {
        top = (node *)malloc(sizeof(struct node));
        top->val = x;
        top->next = NULL;
        l++;
    }
    else
    {
        if (!isfull())
        {
            node *temp = (node *)malloc(sizeof(node));
            temp->val = x;
            temp->next = top;
            top = temp;
            l++;
        }
        else
        {
            printf("Stack is full\n");
        }
    }
}
void pop()
{
    if (!isempty())
    {
        int x = top->val;
        node *t = top;
        top = top->next;
        free(t);
        l--;
        printf("Popped value %d ", x);
        return;
    }
    printf("Stack is empty\n");
}
void peek()
{
    if (!isempty())
    {
        printf("peek is: %d", top->val);
        return;
    }
    printf("Stack is empty\n");
}
void display()
{
    if (!isempty())
    {
        printf("\n stack elememts are: ");
        node *t = top;
        while (t)
        {
            printf("%d ", t->val);
            t = t->next;
        }
        printf("\n");
        return;
    }
    printf("STack is empty\n");
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
            pop();
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
