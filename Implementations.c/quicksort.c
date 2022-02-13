#include <stdio.h>
void quicksort(int arr[], int start, int end)
{
    if (start < end)
    {
        int temp;
        int i = start;
        int j = end;
        int pivot = start;
        while (i < j)
        {
            while (arr[i] <= arr[pivot] && i < end)
                i++;
            while (arr[j] > arr[pivot])
                j--;
            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        quicksort(arr, start, j - 1);
        quicksort(arr, j + 1, end);
    }
}
int main()
{

    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        scanf("%d ", &arr[i]);
    }
    quicksort(arr, 0, 4);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
