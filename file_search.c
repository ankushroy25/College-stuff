#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
int *bbsort(int *a, int size)
{
    int i, j, temp;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (a[j + 1] < a[j])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    return a;
}
void binsearch(int a[], int search, int high)
{
    int low = 0, mid;

    while (low <= high)
    {
        mid = (high + low) / 2;
        if (search > a[mid])
            low = mid + 1;
        else if (search < a[mid])
            high = mid - 1;
        else if (search == a[mid])
        {
            printf("\n%d found at %dth position \n", search, mid + 1);
            return;
        }
        else
        {
            printf("\n%d not found \n", search);
            return;
        }
    }
}
int interpolation(int a[], int search, int low, int high)
{
    // mid = low + ((double)((search - a[mid]) / (a[high] - a[low])) * (high - low));
    //   fraction=(search - a[mid]) / (a[high] - a[low])
    if (low > high)
        return -1;

    int mid = low + (((double)(high - low) / (a[high] - a[low])) * (search - a[low]));

    if (search == a[mid])
        return mid;
    else if (search < a[mid])
        return (interpolation(a, search, low, mid - 1));
    else if (search > a[mid])
        return (interpolation(a, search, mid + 1, high));
}
void printArray(int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
}
int main()
{
    int search, i, size = 0,index;
    printf("Enter the searchement to search :");
    scanf("%d", &search);

    FILE *fptr;

    int *arr = (int *)malloc(MAX * sizeof(int));

    fptr = fopen("random.txt", "r");
    for (i = 0; !feof(fptr); i++) // reading file content into array
    {
        fscanf(fptr, "%d ", &arr[i]);
        size++;
    }
    fclose(fptr);

    arr = bbsort(arr, size);

    printArray(arr, size);
    //binsearch(arr, search, size - 1);
    index=interpolation(arr,search,0,size-1)+1;
    
    if(index>0)
        printf("\nFound at %dth position\n",index);
    else
        printf("\nNot found\n");
    
    return 0;
}