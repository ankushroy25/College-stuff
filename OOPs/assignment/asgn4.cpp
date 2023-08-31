#include <iostream>
using namespace std;

template <class T>
class test
{
    T val;

public:
    test() : val() { cout << "Default constructor" << endl; }
    test(T data) : val(data) { cout << "Parameterized constructor" << endl; }
    test(const test &other) : val(other.val) { cout << "Copy constructor" << endl; }

    test operator+(const test &ob);

    template <class U>
    friend test<U> operator-(test<U> ob1, test<U> ob2);

    T getValue() const { return val; }
    ~test() { cout << "Destructor" << endl; }
};

template <class T>
test<T> test<T>::operator+(const test<T> &ob)
{
    return test<T>(val + ob.val);
}

template <class T>
test<T> operator-(test<T> ob1, test<T> ob2)
{
    return test<T>(ob1.getValue() - ob2.getValue());
}

template <>
test<string> operator-(test<string> ob1, test<string> ob2)
{
    // INCOMPLETE PART DO NOT SUBMIT ASSIGNMENT
    test<string> temp("");
    return temp;
}
int main()
{
    test<string> obj1("cat "), obj2("dog"), obj3("co");
    test<string> res = obj1 + obj2; //- obj3;

    cout << res.getValue() << endl;
    return 0;
}
