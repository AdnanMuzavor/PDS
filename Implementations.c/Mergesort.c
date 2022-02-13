#include <stdio.h>
#include <stdlib.h>
void merge(int *arr, int *temp, int l, int mid, int h)
{
    int i = l;
    int j = mid + 1;
    int k = l;
    while (i <= mid && j <= h)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= h)
    {
        temp[k++] = arr[j++];
    }
}
void copyarr2(int *arr, int *temp, int l, int h)
{
    for (int i = l; i <= h; i++)
    {
        arr[i] = temp[i];
    }
}
int *mergesort(int *arr, int *temp, int l, int h)
{

    if (l < h)
    {
        int mid = (l + h) / 2;
        mergesort(arr, temp, l, mid);
        mergesort(arr, temp, mid + 1, h);
        merge(arr, temp, l, mid, h);
        copyarr2(arr, temp, l, h);
    }
    return arr;
}

int main()
{
    int n, key;
    int arr[50];
    int *res = arr;
    int temp[50];
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
    printf("\nCalling fn\n");
    res = mergesort(arr, temp, 0, n - 1);
    printf("\n");
    printf("Elements of array are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}