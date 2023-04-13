// showing the comparisions for calculations of power of a number for 2 cases -
// 1) in O(n) time
// 2) in log2(n) time
#include <stdio.h>
#include <stdlib.h>

void power1(int x, int n)
{
    int i, prod = 1;

    for (i = 1; i <= n; i++)
    {
        prod *= x;
    }

    printf("\n---O(n) complexity---\n Value = %d\n Comparisions = %d\n", prod, i - 1);
}
void power2(int x, int n)
{
    int prod = 1, c = 0;

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            prod *= x;
            --n;
        }
        else
        {
            x = x * x;
            n /= 2;
            c++;
        }
    }
    printf("\n---O(log2(n)) complexity---\n Value = %d\n Comparisions = %d\n", prod, c);
}

int main()
{
    int x, n;

    printf("Enter number :");
    scanf("%d", &x);
    printf("Enter power :");
    scanf("%d", &n);

    power1(x, n);
    power2(x, n);
    return 0;
}