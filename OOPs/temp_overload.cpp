#include <iostream>
using namespace std;

template <class T1, class T2>
float area(T1 x, T2 y)
{
    return x * y;
}

template <class T>
float area(T x)
{
    return x * x;
}
int main()
{
    float ans;
    cout << "Rectangle" << endl;
    ans = area<int, float>(5, 6);
    cout << ans << endl;

    cout << "Square" << endl;
    ans = area<int>(5);
    cout << ans << endl;

    return 0;
}