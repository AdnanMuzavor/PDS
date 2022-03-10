#include <stdio.h>
#include <stdlib.h>

//ALGORITH FOR QUEUE
struct node
{
    int data;

    struct node *next;

} *front = NULL, *rear = NULL;

int isempty()
{
    if (front == NULL)
    {
        return 1;
    }
    return 0;
}

void enqueue(int x)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    if (t == NULL)
    {
        printf("____full____");
    }
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}
int dequeue()
{
    int x = -1;
    if (front == NULL)
    {
        printf("___stack empty____");
    }
    else
    {
        x = front->data;
        struct node *q = front;
        front = front->next;
        free(q);
    }
    return x;
}

//ALGO FOR BFS SEARCH
void BFS(int G[][7], int start, int n)
{
    int i = start;
    int visited[7] = {0};
    printf("%d ", i);
    visited[i] = 1;
    enqueue(i);
    while (!isempty())
    {
        i = dequeue();
        for (int j = 1; j < n; j++)
        {
            if (G[i][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

int main(){
    int G[7][7]={{0,0,0,0,0,0,0},
                 {0,0,1,1,0,0,0},
                 {0,1,0,0,1,0,0},
                 {0,1,0,0,1,0,0},
                 {0,0,1,1,0,1,1},
                 {0,0,0,0,1,0,0},
                 {0,0,0,0,1,0,0}};

     BFS(G,1,7);     
        printf("_/");
     BFS(G,4,7);
         printf("_/");
     BFS(G,5,7);
         printf("_/");
     BFS(G,3,7);   
}