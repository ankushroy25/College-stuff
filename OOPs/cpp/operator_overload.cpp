#include <iostream>
using namespace std;
class element
{
    int val;

public:
    element() {}
    element(int val) : val(val) {}
    element operator++() { val++; }
    element operator++(int) { val++; }
    element operator--() { val--; }
    element operator--(int) { val--; }
    ostream friend &operator<<(ostream &out, element &ob);
    istream friend &operator>>(istream &in, element &ob);
};
istream &operator>>(istream &in, element &ob)
{
    in >> ob.val;
}
ostream &operator<<(ostream &out, element &ob)
{
    out << ob.val;
}

int main()
{
    element a, b;
    cout << "Enter 2 values : ";
    cin >> a;
    cin >> b;

    cout << "Initial values : " << a << " , " << b << endl;

    cout << "Pre increment : ";
    ++a;
    ++b;
    cout << a << " , " << b << endl;

    cout << "Post increment : ";
    a++;
    b++;
    cout << a << " , " << b << endl;

    cout << "Pre decrement : ";
    --a;
    --b;
    cout << a << " , " << b << endl;

    cout << "Post decrement : ";
    a--;
    b--;
    cout << a << " , " << b << endl;

    return 0;
}