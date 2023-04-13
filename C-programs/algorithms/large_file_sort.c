// generate random numbers into a file and then read and sort the file data and store in another file with ni, of comaprsuons and time taken
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int heapify(int *arr, int n, int i)
{
    int largest = i, count = 0;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        count += heapify(arr, n, largest);
    }
    count++;
    return count;
}

int heapSort(int *arr, int n)
{
    int i, temp, count = 0;
    for (i = n / 2 - 1; i >= 0; i--)
        count += heapify(arr, n, i);

    for (i = n - 1; i >= 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        count += heapify(arr, i, 0);
    }
    return count;
}

int main()
{
    srand(time(NULL));
    int i = 0, j = 0, comp = 0, n = 10;
    int *ar;
    FILE *fp, *fp2;
    double tm, start, end;
    ar = (int *)malloc(sizeof(int) * n);

    fp = fopen("fileRandom.txt", "w");
    for (j = 0; j < 5; j++)
    {
        fprintf(fp, "---Random Set %d---\n", j + 1);
        for (i = 0; i < n; i++)
            fprintf(fp, "%d ", rand() % 100);

        fprintf(fp, "\n");
    }
    fclose(fp);

    fp = fopen("fileRandom.txt", "r");
    fp2 = fopen("fileSorted.txt", "w");

    for (j = 0; j < 5; j++)
    {
        fscanf(fp, "%*[^\n]");
        for (i = 0; i < n; i++)
            fscanf(fp, "%d ", &ar[i]);

        start = clock();
        comp += heapSort(ar, n);
        end = clock();
        tm = (end - start) / CLOCKS_PER_SEC;

        fprintf(fp2, "---Sorted Set %d---\n", j + 1);
        for (i = 0; i < n; i++)
            fprintf(fp2, "%d ", ar[i]);

        fprintf(fp2, "\nSorting time : %fs\n", tm);
    }
    fprintf(fp2, "\nAvg. No. of comparisions : %d\n", comp / 3);

    fclose(fp);
    fclose(fp2);

    return 0;
}
