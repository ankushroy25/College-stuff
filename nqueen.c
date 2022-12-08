#include <stdio.h>
#include <math.h>
int n;
int isSafe(int row, int col, char board[n][n])
{
    // horizontal
    for (int i = 0; i < n; i++)
    {
        if (board[row][i] == 'Q')
        {
            return -1;
        }
    }

    // vertical
    for (int i = 0; i < n; i++)
    {
        if (board[i][col] == 'Q')
        {
            return -1;
        }
    }

    // upper left
    for (int c = col, r = row; c >= 0 && r >= 0; c--, r--)
    {
        if (board[r][c] == 'Q')
        {
            return -1;
        }
    }

    // upper right
    for (int c = col, r = row; c < n && r >= 0; c++, r--)
    {
        if (board[r][c] == 'Q')
        {
            return -1;
        }
    }

    // lower left
    for (int c = col, r = row; c >= 0 && r < n; c--, r++)
    {
        if (board[r][c] == 'Q')
        {
            return -1;
        }
    }

    // lower right
    for (int c = col, r = row; c < n && r < n; c++, r++)
    {
        if (board[r][c] == 'Q')
        {
            return -1;
        }
    }

    return 1;
}
void display(char allBoards[100][n][n])
{
       for (int i = 0; i<2 ; i++)
       {
           printf("%dth board\n",(i+1));
           for (int j = 0; j < n; j++)
           {
               for (int k = 0; k < n; k++)
               {
                   printf("%c ",allBoards[i][j][k]);
               }
               printf("\n");
           }
       }
}
void ansBoard(char board[n][n], char allBoards[100][n][n])
{
    char row[n];
    int i, j, k;

    for(i=0;i<100;i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                if (board[j][k] == 'Q')
                    allBoards[i][j][k] = 'Q';
                else
                    allBoards[i][j][k] = 'x';
            }
        }
        if(j==n && k==n)
            break;
    }

    display(allBoards);
}

void backtrack(char board[][n], char allBoards[100][n][n], int col)
{
    if (col == n)
    {
        ansBoard(board, allBoards);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board))
        {
            board[row][col] = 'Q';
            backtrack(board, allBoards, col + 1);
            board[row][col] = 'x';
        }
    }
}
void solve()
{
    char allBoards[n][n][n];
    char board[n][n];

    backtrack(board, allBoards, 0);
}


int main()
{

    printf("Enter nxn chess board size :");
    scanf("%d", &n);

    solve();

    return 0;
}