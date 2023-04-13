// print all the possible permutations of a given array into a file and count the number of comparisions for the total sorting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int comp = 0, size = 0;
int partition(int *a, int start, int end)
{
    int i, j, pivot, randidx;

    randidx = start + (rand() % (end - start + 1));
    swap(&a[randidx], &a[end]);
    pivot = a[end];
    i = start;
    for (j = start; j < end; j++)
    {
        comp++;
        if (a[j] < pivot)
        {
            swap(&a[i], &a[j]);
            i++;
        }
    }
    swap(&a[i], &a[end]);
    return i;
}
void quicksort(int *a, int start, int end)
{
    if (start > end)
        return;

    int pividx = partition(a, start, end);
    quicksort(a, start, pividx - 1);
    quicksort(a, pividx + 1, end);
}
void printarray(int arr[], int size, FILE *fp)
{
    int i;
    for (i = 0; i < size; i++)
    {
        fprintf(fp, "%d  ", arr[i]);
    }
    fprintf(fp, "\n");
}

void permutation(int *arr, int start, int end, FILE *fp)
{
    if (start == end)
    {
        ++size;
        printarray(arr, end + 1, fp);
        return;
    }
    int i;
    for (i = start; i <= end; i++)
    {
        swap(&arr[i], &arr[start]);
        permutation(arr, start + 1, end, fp);
        swap(&arr[i], &arr[start]);
    }
}
int main()
{
    srand(time(NULL));
    int i, j, n, ans = 0;
    double start, end;

    printf("Enter the size of array :");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));

    FILE *fptr;
    fptr = fopen("permutationFile.txt", "w");

    for (i = 0; i < n; i++)
        arr[i] = i + 1;

    printf("Permutations written on file \"permutationFile.txt\"\n");
    start = clock();
    permutation(arr, 0, n - 1, fptr);
    end = clock();
    printf("File generating time : %f\n", (end - start) / CLOCKS_PER_SEC);

    fclose(fptr);

    fptr = fopen("permutationFile.txt", "r");
    start = clock();
    while (!feof(fptr))
    {
        for (j = 0; j < n; j++)
        {
            fscanf(fptr, "%d", &arr[j]);
        }
        quicksort(arr, 0, n - 1);
    }
    end = clock();
    fclose(fptr);

    printf("Sorting time : %f\n", (end - start) / CLOCKS_PER_SEC);
    printf("Avg no. of comparisions : %f\n", (double)comp / size);

    free(arr);
    return 0;
}