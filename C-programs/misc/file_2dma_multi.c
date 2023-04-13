// matrix multiplication using dma for whose dimensions and inputs are read from 2 separate files and the result matrix is stored in a 3rd file.

// including the header files
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
// NOTE: If you are using c99 version or earlier, please write each of the function prototypes !!`

// memory allocation for the 2d matrix
int **allocate(int **a, int r, int c)
{ // since we return a double pointer type array the function type is int** as well
    int i, j;
    for (i = 0; i < r; i++)
    {
        // a dma of pointer which points to the respective row array by dma
        a[i] = (int *)malloc(sizeof(int) * c);
    }
    return a;
}

// read the dimensions and matrix elements from the file
void readData(FILE *fptr, int r, int c, int **a)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            // reading the digits of the matrix from the file
            fscanf(fptr, "%d", (*(a + i) + j)); // pointer type for address- &a[i][j] notation = (*(a + i) + j)
        }
    }
}

// matrix multiplication operation
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
}

// writing the resultant matrix to the 3rd file
void fileWrite(int **a, int r, int c)
{
    // opening file in write mode
    FILE *fptr = fopen("result.txt", "w");

    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            fprintf(fptr, "%d ", *(*(a + i) + j)); // pointer type for value- a[i][j] notation = *(*(a + i) + j)
        }
        fprintf(fptr, "\n");
    }
    fclose(fptr);
}

// free the memory allocated for the matrices
void freeMemory(int **a, int r)
{
    for (int i = 0; i < r; i++)
    {
        free(*(a + i)); // free each rows of the matrix attached to the pointers
    }
}
int main()
{
    int r1, r2, c1, c2;

    FILE *fp1, *fp2;

    // opening files in read mode
    fp1 = fopen("matrixA.txt", "r");
    fp2 = fopen("matrixB.txt", "r");

    fscanf(fp1, "%d %d", &r1, &c1);
    fscanf(fp2, "%d %d", &r2, &c2);

    // checking criterion for possibililty of matrix multiplication i.e. row2 should equal col1
    if (r2 != c1)
    {
        printf("matrix multiplication not possible");
        exit(1);
    }

    // allocate the pointer array which will contain dma for each rows of the matrices
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
    // closing the files

    multiplication(arr1, arr2, ans, r1, r2, c2);
    fileWrite(ans, r1, c2);

    // memory release to do write more codes :P
    freeMemory(arr1, r1);
    freeMemory(arr2, r2);
    freeMemory(ans, r1);

    return 0;
} // end

// Author - Ankush Roy