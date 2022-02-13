/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
void swap(int a, int b)
{

    int temp = a;
    a = b;
    b = temp;
}
int *sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {

                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Elements of array are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return arr;
}
void LinearS(int *arr, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("%d found at %d\n", key, i + 1);
            return;
        }
    }
    printf("%d not found\n", key);
}
void BinaryS(int *arr, int n, int key)
{
    int l = 0, h = n - 1, mid = -1;
    arr = sort(arr, n);
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (arr[mid] == key)
        {
            printf("%d found\n", key);
            return;
        }
        else if (arr[mid] < key)
            l = mid + 1;
        else
            h = mid - 1;
    }
    printf("\n%d not found\n", key);
}
int main()
{
    int n, key;
    int arr[50];
    printf("Enter size of your array: ");
    scanf("%d", &n);
    printf("\n");
    printf("Enetr elements of your array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Elements of array are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n Enter elemet you want search: ");
    scanf("%d", &key);
    printf("\n");
    LinearS(arr, n, key);
    BinaryS(arr, n, key);
    return 0;
}