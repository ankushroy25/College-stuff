#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, start = 0, end, maxind = 0, minind = 0, temp;

    printf("Enter array size: ");
    scanf("%d", &n);
    end = n - 1;

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    while (start < end)
    {
        maxind=start;
        minind=end;
        for (int i = start; i <= end; i++)
        {
            if (arr[i] > arr[maxind])
            {
                maxind = i;
            }
            if (arr[i] < arr[minind])
            {
                minind = i;
            }
        }
        temp = arr[maxind];
        arr[maxind] = arr[end];
        arr[end] = temp;

        temp = arr[minind];
        arr[minind] = arr[start];
        arr[start] = temp;

        start++;
        end--;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}