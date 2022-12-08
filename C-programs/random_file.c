//program to generate random numbers (non repititative) and strore it in a file and then fetch from the file and sort using insertion sort order
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
int random(int upper)
{
    int lower = 1, x;
    x = (rand() % (upper - lower + 1)) + lower;
    return x;
}
void insertionSort(int *a, int n)
{
    int i, j, temp;

    for (i = 1; i < n; i++)
    {
        temp = a[i]; // this var is imp else the i index value gets replaced when Aj+1=Aj is done
        for (j = i - 1; (j >= 0 && temp < a[j]); j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
}
int isPresent(int *a, int search, int n)
{
    int i;
    for (i = 0; i <= n; i++)
    {
        if (a[i] == search)
            return 1;
    }
    return 0;
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
    srand(time(NULL));
    int i, num, limit;

    printf("Input random number limit :");
    scanf("%d", &limit);

    int *arr = (int *)calloc(limit, sizeof(int));
    FILE *fptr;

    fptr = fopen("random.txt", "w");
    for (i=0;i < limit;) // writing on file
    {
        num = random(limit);
        if (isPresent(arr, num, i))
            continue;
        else
        {
            arr[i++] = num;
            fprintf(fptr, "%d ", num);
        }
    }
    fclose(fptr);

    fptr = fopen("random.txt", "r");
    for (i = 0; !feof(fptr); i++) // reading file content into array
    {
        fscanf(fptr, "%d ", &arr[i]);
    }
    fclose(fptr);

    printf("Unsorted file - ");
    printArray(arr, limit);

    insertionSort(arr, limit);

    printf("\nSorted array - ");
    printArray(arr, limit);

    return 0;
}