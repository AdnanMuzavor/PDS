#include <stdio.h>

#define I 31167

int main()
{
    int cost[8][8] = {{I, I, I, I, I, I, I, I},
                      {I, I, 25, I, I, I, 5, I},
                      {I, 20, I, 12, I, I, I, 10},
                      {I, I, 12, I, 8, I, I, I},
                      {I, I, I, 8, I, 16, I, 14},
                      {I, I, I, I, 16, I, 20, 18},
                      {I, 5, I, I, I, 20, I, I},
                      {I, I, 10, I, 14, 18, I, I}};

    int t[2][6];
    int near[8] = {I, I, I, I, I, I, I, I};
    int min = I;
    //SEARCHING FOR FIRST MIN VERTEX
    int i, j, k, u, v, n = 7;
    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (cost[i][j] < min)
            {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }
    t[0][0] = u;
    t[1][0] = v;
    near[u] = near[v] = 0;
    for (j = 1; j <= n; j++)
    {

        if (near[j] != 0)
        {
            if (cost[j][u] < cost[j][v])
            {
                near[j] = u;
            }
            else
            {
                near[j] = v;
            }
        }
    }

    //FOR PUTTING OTHER NOS TOO
    //IN ARRAY 0,0 and 1,0 USED NOW INCASE OF COLUMS WE NEED TO START FROM 1 AND GO TILL 5 i.e <N-1

    for (i = 1; i < n - 1; i++)
    {
        min = I;
        for (j = i; j <= n; j++)
        {
            if (near[i] != 0 && cost[j][near[j]] < min)
            {
                min = cost[j][near[j]];
                k = j;
            }
        }

        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;

        for (j = 1; j <= n; j++)
        {
            if (near[j] != 0 && cost[j][k] < cost[j][near[j]])
            {
                near[j] = k;
            }
        }
    }
    for (i = 0; i < n - 1; i++)
    {
        printf("( %d,%d )", t[0][i], t[1][i]);
    }
}