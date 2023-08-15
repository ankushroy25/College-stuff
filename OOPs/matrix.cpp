#include <iostream>
using namespace std;

class matrix
{

public:
    int row, col;
    int **arr;
    matrix()
    {
        row = 0;
        col = 0;
    }
    void allocate(int r, int c)
    {
        row = r;
        col = c;
        arr = new int *[row];
        for (int i = 0; i < row; ++i)
        {
            arr[i] = new int[col]();
        }
    }
    void input()
    {
        int el;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> arr[i][j];
            }
        }
    }
    void display()
    {
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    int **add(int **obArr)
    {

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr[i][j] += obArr[i][j];
            }
        }
        return arr;
    }
    int **subtract(int **obArr)
    {

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr[i][j] -= obArr[i][j];
            }
        }
        return arr;
    }
    int **multiply(int **obArr, int obr2, int obc2)
    {
        int r1 = row, r2 = obr2, c2 = obc2;
        int **res = new int *[r1];

        for (int i = 0; i < r1; i++)
        {
            res[i] = new int[c2];
            for (int j = 0; j < c2; j++)
            {
                res[i][j] = 0;
                for (int k = 0; k < r2; k++)
                {
                    res[i][j] += arr[i][k] * obArr[k][j];
                }
            }
        }

        return res;
    }
    ~matrix()
    {
        // cout << "Destroy object" << endl;
        for (int i = 0; i < row; ++i)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
};

int main()
{
    int r1, c1, r2, c2, ch;

    do
    {
        cout << "Menu \n1-Addition \n2-Subtraction \n3-Multiplication \n4-Exit \n>Enter your choice :";
        cin >> ch;

        cout << "Enter row and column of 1st matrix :  ";
        cin >> r1 >> c1;
        matrix m1;
        m1.allocate(r1, c1);
        cout << "Enter row and column of 2nd matrix :  ";
        cin >> r2 >> c2;
        matrix m2;
        m2.allocate(r2, c2);

        cout << "Enter matrix A elements row-wise :-" << endl;
        m1.input();
        cout << "Enter matrix B elements row-wise :-" << endl;
        m2.input();
        matrix M;

        switch (ch)
        {
        case 1:
            M.allocate(r1, c1);
            cout << "Added Result" << endl;
            M.arr = m1.add(m2.arr);
            M.display();
            break;
        case 2:
            M.allocate(r1, c1);
            cout << "Subtracted Result" << endl;
            M.arr = m1.subtract(m2.arr);
            M.display();
            break;
        case 3:
            if (r2 != c1)
            {
                cout << "Multiplication not possible" << endl;
                break;
            }
            M.allocate(r1, c1);
            M.arr = m1.multiply(m2.arr, m2.row, m2.col);
            cout << "Multiplied Result" << endl;
            M.display();

            break;
        case 4:
            cout << "Program exit" << endl;
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }

    } while (ch != 4);

    return 0;
}
