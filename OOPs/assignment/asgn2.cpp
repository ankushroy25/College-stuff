#include <iostream>
using namespace std;
class test
{
    char *s;

public:
    friend istream &operator>>(istream &, test &c);
    friend ostream &operator<<(ostream &, test &c);
};

istream &operator>>(istream &in, test &c)
{
    c.s = new char[100];
    in >> c.s;
    return in;
}
ostream &operator<<(ostream &out, test &c)
{
    out << c.s;
    return out;
}
int main()
{
    test obj;
    cout << "Enter input" << endl;
    cin >> obj;

    cout << obj;
    return 0;
}