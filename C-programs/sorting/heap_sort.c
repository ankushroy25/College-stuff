#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int heapify(int *arr, int n, int i)
{
    int largest = i, count = 0;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        count++;
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        count += heapify(arr, n, largest);
    }
    return count;
}

int heapSort(int *arr, int n)
{
    int i, temp, count = 0;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        count += heapify(arr, n, i);
    }

    for (i = n - 1; i >= 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        count += heapify(arr, i, 0);
    }
    return count;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main()
{
    srand(time(NULL));
    int n, i, comparisions = 0;

    printf("Enter size of array :");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    // printf("Input array elements:-\n");
    for (i = 0; i < n; i++)
        arr[i] = i + 1;
    // arr[i] = rand() % 1000;

    printf("Random generated array :");
    printArray(arr, n);

    comparisions = heapSort(arr, n);

    printf("\nSorted array\t: ");
    printArray(arr, n);
    printf("\nNo. of comparisions : %d", comparisions);
}
