#include <iostream>
using namespace std;

class test
{
    int val;

public:
    test() : val(0) { cout << "Default constructor" << endl; }
    test(int data) : val(data) { cout << "Parameterized constructor" << endl; }
    test(const test &other) : val(other.val) { cout << "copy con" << endl; }

    test operator+(test &ob);
    friend test operator-(test ob1, test ob2);
    int getValue() { return val; }
    ~test() { cout << "Destructor" << endl; }
};
test test::operator+(test &ob)
{
    return test(val + ob.val);
}
test operator-(test ob1, test ob2)
{
    return test(ob1.val - ob2.val);
}
int main()
{
    test obj1(1), obj2(12), obj3(5);
    test res = obj1 + obj2 - obj3;

    cout << res.getValue() << endl;
    return 0;
}