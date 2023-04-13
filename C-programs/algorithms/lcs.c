#include <stdio.h>
#include <string.h>
#define N 100

int L[N][N];
char lcs[N][N];

int LCS(char X[], char Y[], int m, int n)
{
    int i, j;
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                L[i][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1])
            {
                L[i][j] = L[i - 1][j - 1] + 1;
                lcs[i - 1][j - 1] = X[i - 1];
            }
            else
            {
                if (L[i - 1][j] >= L[i][j - 1])
                {
                    L[i][j] = L[i - 1][j];
                }
                else
                {
                    L[i][j] = L[i][j - 1];
                }
            }
        }
    }
    return L[m][n];
}

void findLCS(int i, int j, int len, char str[], int lcs_len)
{
    static int count = 0;
    static char printedCheck[N * N][N] = {0};
    if (i == 0 || j == 0)
    {
        if (len == -1)
        {
            int k;
            for (k = 0; k < count; k++)
            {
                if (strcmp(printedCheck[k], str) == 0)
                    return;
            }
            printf("%s\n", str);
            strcpy(printedCheck[count], str);
            count++;
        }
        return;
    }
    if (lcs[i - 1][j - 1] == '\0')
    {
        findLCS(i - 1, j, len, str, lcs_len);
        findLCS(i, j - 1, len, str, lcs_len);
    }
    else
    {
        str[len] = lcs[i - 1][j - 1];
        findLCS(i - 1, j - 1, len - 1, str, lcs_len);
    }
}

int main()
{
    char X[] = "abcabcaa";
    char Y[] = "acbacba";
    int m = strlen(X);
    int n = strlen(Y);

    int length = LCS(X, Y, m, n);

    char str[length];
    findLCS(m, n, length - 1, str, length);

    return 0;
}