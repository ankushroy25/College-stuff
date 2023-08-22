#include <iostream>
using namespace std;
template <class T>
class matrix
{
    T **m;
    int row, col;

public:
    matrix(int r, int c);
    matrix() {}
    matrix operator*(matrix obj);
    void display()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
    }
    ~matrix()
    {
        for (int i = 0; i < row; i++)
            delete m[i];
        delete m;
    }
};
template <class T>
matrix<T>::matrix(int r, int c) : row(r), col(c)
{
    m = new T *[row];
    for (int i = 0; i < row; i++)
        m[i] = new T[col];
    cout << "Enter values" << endl;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> m[i][j];
}
template <class T>
matrix<T> matrix<T>::operator*(matrix<T> obj)
{
    matrix<T> result;
    result.row = row;
    result.col = obj.col;
    result.m = new T *[result.row];
    for (int i = 0; i < result.row; i++)
        result.m[i] = new T[result.col]();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < obj.col; j++)
        {
            for (int k = 0; k < col; k++)
                result.m[i][j] += m[i][k] * obj.m[k][j];
        }
    }
    return result;
}

int main()
{
    matrix<int> m1(2, 3);
    matrix<int> m2(3, 2);
    cout << "1st matrix" << endl;
    m1.display();
    cout << "2nd matrix" << endl;
    m2.display();
    matrix<int> m3 = m1 * m2;
    cout << "Result matrix" << endl;
    m3.display();
    return 0;
}
