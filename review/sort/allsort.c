#include <stdio.h>
#include <stdlib.h>

void bubblesort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    return;
}

void insertionsort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    return;
}

void selectionsort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int minindex = i; // 表示下标
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minindex])
                minindex = j;
        }
        int tmp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = tmp;
    }

    return;
}

int partion(int *arr, int low, int high)
{
    int j = low;
    int i = j - 1;
    while (j < high)
    {
        if (arr[j] < arr[high])
        {
            i++;
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
        j++;
    }
    int tmp = arr[high];
    arr[high] = arr[i + 1];
    arr[i + 1] = tmp;

    return i + 1;
}
void quicksort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partion(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }

    return;
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
} // 固定格式

void printarray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}
int main()
{
    int arr[10] = {1, 5, 7, 3, 8, 9, 12, 4, 6, 3};
    // bubblesort(arr,10);
    // insertionsort(arr,10);
    // selectionsort(arr,10);
    // quicksort(arr,0,9);  //low,high为下标
    qsort(arr, 10, sizeof(int), compare);
    printarray(arr, 10);

    return 0;
}