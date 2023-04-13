// matrix multiplication using dma for whose dimensions and inputs are read from 2 separate files and the result matrix is stored in a 3rd file.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int **allocate(int **a, int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        a[i] = (int *)malloc(sizeof(int) * c);
    }

    return a;
}
void readData(FILE *fptr, int r, int c, int **a)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            fscanf(fptr, "%d", (*(a + i) + j));
        }
    }
}
int **multiplication(int **a, int **b, int **ans, int r1, int r2, int c)
{
    int i, j, k, sum = 0;
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c; j++)
        {
            sum = 0;
            for (k = 0; k < r2; k++)
            {
                sum += a[i][k] * b[k][j];
            }
            ans[i][j] = sum;
        }
    }

    return ans;
}
void fileWrite(int **a, int r, int c)
{
    FILE *fptr = fopen("result.txt", "w");

    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            fprintf(fptr, "%d ", *(*(a + i) + j));
        }
        fprintf(fptr, "\n");
    }
    fclose(fptr);
}
void freeMemory(int **a, int r)
{
    for (int i = 0; i < r; i++)
    {
        free(*(a + i));
    }
}
int main()
{
    int r1, r2, c1, c2;

    FILE *fp1, *fp2;

    fp1 = fopen("matrixA.txt", "r");
    fp2 = fopen("matrixB.txt", "r");

    fscanf(fp1, "%d %d", &r1, &c1);
    fscanf(fp2, "%d %d", &r2, &c2);

    if (r2 != c1)
    {
        printf("matrix multiplication not possible");
        exit(1);
    }

    int **arr1 = (int **)malloc(r1 * sizeof(int *));
    int **arr2 = (int **)malloc(r2 * sizeof(int *));
    int **ans = (int **)calloc(r1, sizeof(int *));

    arr1 = allocate(arr1, r1, c1);
    arr2 = allocate(arr2, r2, c2);
    ans = allocate(ans, r1, c2);

    readData(fp1, r1, c1, arr1);
    readData(fp2, r2, c2, arr2);
    fclose(fp1);
    fclose(fp2);

    ans = multiplication(arr1, arr2, ans, r1, r2, c2);
    fileWrite(ans, r1, c2);

    freeMemory(arr1, r1);
    freeMemory(arr2, r2);
    freeMemory(ans, r1);

    return 0;
}