#include <stdio.h>

void DFS(int G[][7], int start, int n)
{
    int j;
    static int visited[7] = {0};
    //AS RECURSIVE WE NEED UPDATED VISISTED ARRAY AT EACH RECURSION SI MADE STATIC
    if (visited[start] == 0)
    {
        printf("%d ", start);
        visited[start] = 1;
        for (j = 1; j < n; j++)
        {
            if (G[start][j] == 1 && visited[j] == 0)
            {
                DFS(G, j, n);
            }
        }
    }
}

int main()
{
    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};

//RESULT FOR ALL 4 CANNOT SEEN TOGETHER AS STATIC ARR IS USED

    //DFS(G, 1, 7);
    printf("_/");
   // DFS(G, 4, 7);
    printf("_/");
  //  DFS(G, 5, 7);
    printf("_/");
    DFS(G, 3, 7);
}