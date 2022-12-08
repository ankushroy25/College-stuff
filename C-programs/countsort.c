#include <stdio.h>
#include <stdlib.h>
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
void countsort(int *a, int n)
{
    int i, j, k, maxnum = a[0];

    for (i = 0; i < n; i++)
    {
        maxnum = MAX(maxnum, a[i]);
    }

    int *freq = (int *)calloc((maxnum + 1), sizeof(int));
    //array for frequency of each elements as index count
    for (i = 0; i < n; i++)
    {
        ++freq[a[i]];
    }

    i = 0, j = 0;
    while (i <= maxnum)
    {
        if (freq[i] == 0)
            i++;
        else
        {
            a[j] = i;
            j++;
            --freq[i];
        }   
    }
}

int main()
{
    int i, n;

    printf("Enter array size");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter array elements :-\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Array after sorting :-\n");
    countsort(arr, n);

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}