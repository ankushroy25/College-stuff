// Write two different classes A and B. Each of them has private data member
//  data1 and data2, respectively. Write a function addBoth ( ) to add the values
//  contained in data1 and data2. Pass the object reference as arguments.

#include <iostream>
using namespace std;
class A
{
private:
    int data1;

public:
    A(int value) : data1(value) {}

    int getData1() const
    {
        return data1;
    }
};

class B
{
private:
    int data2;

public:
    B(int value) : data2(value) {}

    int getData2() const
    {
        return data2;
    }
};

int addBoth(const A &objA, const B &objB)
{
    return objA.getData1() + objB.getData2();
}

int main()
{
    A objA(5);
    B objB(10);

    int result = addBoth(objA, objB);
    cout << "Sum of data1 and data2: " << result << endl;

    return 0;
}
