#include <stdio.h>
#include <stdlib.h>

void bubblesort(int *a, int n)
{
    int i, j, temp;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; i < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void selecSort(int *a, int n)
{
    int i, j, temp, idx;
    for (i = 0; i < n - 1; i++)
    {
        idx = i;
        for (j = i + 1; i < n; j++)
        {
            if (a[j] < a[idx])
                idx = j;
        }
        temp = a[idx];
        a[idx] = a[i];
        a[i] = temp;
    }
}
void countSort(int *a, int n)
{
    int i, j, max = a[0], temp;

    for (i = 0; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }

    int *freq = (int *)calloc(max + 1, sizeof(int));

    for (i = 0; i <n; i++)
    {
        ++freq[a[i]];
    }

    i = j = 0;
    while (i <= max)
    {
        if (freq[i] == 0)
            i++;
        else
        {
            a[j++] = i;
            freq[i]--;
        }
    }
}

void insertionSort(int *a, int n)
{
    int i, j, temp, idx;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        for (j = i - 1; (j >= 0 && temp < a[j]); j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
}

void printArray(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
int main()
{
    int ch, n, i;

    printf("Enter size of array :");
    scanf("%d", &n);

    char cont;
    int *arr = (int *)malloc(sizeof(int) * n);

    printf("Enter array elements :");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printArray(arr, n);
    printf("\tMENU \n1-Bubble sort \n2-Selection sort \n3-Count sort \n4-Insertion sort \n5-Quicksort \n");
    do
    {
        printf("\nEnter your choice :");
        scanf("%d", &ch);
        printf("Choice = %d", ch);
        switch (ch)
        {
        case 1:
            printf("\nSorted array\n");
            bubblesort(arr, n);
            printArray(arr, n);
            break;
        case 2:
            printf("\nSorted array\n");
            selecSort(arr, n);
            printArray(arr, n);
            break;
        case 3:
            printf("\nSorted array\n");
            countSort(arr, n);
            printArray(arr, n);
            break;
        case 4:
            printf("\nSorted array\n");
            insertionSort(arr, n);
            printArray(arr, n);
            break;
        // case 5:
        // printf("Sorted array\n");    bubblesort(arr, n);
        //
        //     printArray(arr, n);
        //     break;
        default:
            printf("Invalid choice");
        }

        printf("Press 'y' to continue :");
        scanf("%s", &cont);

    } while (cont == 'y');

    return 0;
}