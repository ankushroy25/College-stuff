// Write a program in C++ to swap the public data members of one class using
// a. pass by value
// b. pass by reference
// c. pass by address
// You will write three non-member functions for swapping and use method
// overloading, whenever possible.

#include <iostream>
using namespace std;

class Swappable
{
public:
    int value1;
    int value2;
};

//  swap using pass by value
void swapval(Swappable obj1, Swappable obj2)
{
    Swappable temp = obj1;
    obj1 = obj2;
    obj2 = temp;
}

//  swap using pass by reference
void swap(Swappable &obj1, Swappable &obj2)
{
    Swappable temp = obj1;
    obj1 = obj2;
    obj2 = temp;
}

// swap using pass by address
void swap(Swappable *obj1, Swappable *obj2)
{
    Swappable temp = *obj1;
    *obj1 = *obj2;
    *obj2 = temp;
}

int main()
{
    Swappable objA = {1, 2};
    Swappable objB = {3, 4};

    cout << "Before swapping:" << endl;
    cout << "objA: " << objA.value1 << ", " << objA.value2 << endl;
    cout << "objB: " << objB.value1 << ", " << objB.value2 << endl;

    // Swap using pass by value
    swapval(objA, objB);
    cout << "\nAfter swapping using pass by value:" << endl;
    cout << "objA: " << objA.value1 << ", " << objA.value2 << endl;
    cout << "objB: " << objB.value1 << ", " << objB.value2 << endl;

    // Swap using pass by reference - working
    swap(objA, objB);
    cout << "\nAfter swapping using pass by reference:" << endl;
    cout << "objA: " << objA.value1 << ", " << objA.value2 << endl;
    cout << "objB: " << objB.value1 << ", " << objB.value2 << endl;

    // Swap using pass by address - working
    swap(&objA, &objB);
    cout << "\nAfter swapping using pass by address:" << endl;
    cout << "objA: " << objA.value1 << ", " << objA.value2 << endl;
    cout << "objB: " << objB.value1 << ", " << objB.value2 << endl;

    return 0;
}
