#include <iostream>
#include <string>
using namespace std;
template <class T>
class Test
{
    T a;

public:
    Test(T x) : a(x) {}
    Test operator+(Test &t)
    {
        return a + t.a;
    }
    template <class U>
    friend Test<U> operator-(Test<U> &, Test<U> &);
    void display()
    {
        cout << "Result = " << a << endl;
    }
};
template <class U>
Test<U> operator-(Test<U> &t1, Test<U> &t2)
{
    return t1.a - t2.a;
}
template <>
Test<string> operator-(Test<string> &t1, Test<string> &t2)
{
    Test<string> res("");
    int flag[26];
    for (int i = 0; i < t2.a.length(); i++)
        flag[t2.a[i] - 'a'] = -1;
    for (int i = 0; i < t1.a.length(); i++)
    {
        if (flag[t1.a[i] - 'a'] != -1)
            (res.a) += t1.a[i];
    }
    return res;
}
int main()
{
    string x, y, z;
    char x1, y1, z1;
    cout << "Enter three characters :";
    cin >> x1 >> y1 >> z1;
    Test<char> obj1(x1), obj2(y1), obj3(z1);
    Test<char> res1 = obj1 - obj2 + obj3;
    res1.display();

    cout << "Enter three strings :";
    cin >> x >> y >> z;
    Test<string> obj4(x), obj5(y), obj6(z);
    Test<string> res2 = obj4 - obj5 + obj6;
    res2.display();
    return 0;
}
