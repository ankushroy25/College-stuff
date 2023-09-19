#include <iostream>
using namespace std;
class matrix
{
    int row, col;
    int **arr;

public:
    matrix() { cout << "Default constructor" << endl; }
    matrix(int r, int c);
    // matrix(const matrix &ob);
    matrix operator+(matrix &ob);
    matrix operator-(matrix &ob);
    matrix operator*(matrix obj);
    void display();
    void input();
    ~matrix();
};
void matrix::input()
{
    cout << "Enter matrix elements :-" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cin >> arr[i][j];
    }
}
matrix::matrix(int r, int c) : row(r), col(c)
{
    cout << "Parameterized  constructor" << endl;
    arr = new int *[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col]();
    }
}
// matrix::matrix(const matrix &ob)
// {
//     cout << "copy constructor" << endl;

//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             arr[i][j] = ob.arr[i][j];
//         }
//     }
// }
matrix matrix::operator+(matrix &ob)
{
    matrix res(row, ob.col);
    cout << "inside +" << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            res.arr[i][j] = arr[i][j] + ob.arr[i][j];
        }
    }
    return res;
}
matrix matrix::operator-(matrix &ob)
{
    matrix res;
    res.row = row;
    res.col = col;
    res.arr = new int *[row];
    for (int i = 0; i < row; i++)
    {
        res.arr[i] = new int[col]();
        for (int j = 0; j < col; j++)
        {
            res.arr[i][j] = arr[i][j] - ob.arr[i][j];
        }
    }
    res.display();
    return res;
}

matrix matrix::operator*(matrix obj)
{
    matrix result(row, obj.col);
    for (int i = 0; i < row; i++)
        result.arr[i] = new int[obj.col]();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < obj.col; j++)
        {
            for (int k = 0; k < col; k++)
                result.arr[i][j] += arr[i][k] * obj.arr[k][j];
        }
    }
    return result;
}
void matrix::display()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
}
matrix::~matrix()
{
    cout << "destructor" << endl;

    for (int i = 0; i < row; i++)
        delete arr[i];
    delete arr;
}
int main()
{
    int r1, c1, r2, c2;
    cout << "Matrix 1 dimensions : ";
    cin >> r1 >> c1;
    cout << "Matrix 2 dimensions : ";
    cin >> r2 >> c2;
    if (r1 != r2 && c1 != c2)
    {
        cout << "Matrix add/subtract not possible" << endl;
        return 0;
    }

    matrix m1(r1, c1);
    matrix m2(r2, c2);
    m1.input();
    m2.input();
    cout << "1st matrix" << endl;
    m1.display();
    cout << "2nd matrix" << endl;
    m2.display();
    matrix m3 = m1 + m2;
    cout << "Added matrix" << endl;
    m3.display();

    cout << "--------------------" << endl;
    m3 = m2 - m1;
    cout << "Subtracted matrix" << endl;
    m3.display();
    cout << "End" << endl;

    return 0;
}
