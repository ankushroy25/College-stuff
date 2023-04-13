// no. of comparisons for insertion sort
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, n, temp, c = 0;

    printf("Enter size  of array :");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));

    printf("Input array elements :");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && temp < arr[j])
        {
            c++;
            arr[j + 1] = arr[j];
            j--;
        }
        c++;
        arr[j + 1] = temp;
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nComparisions : %d ", c);

    return 0;
}