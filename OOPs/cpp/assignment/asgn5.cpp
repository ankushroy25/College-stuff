#include <iostream>
using namespace std;

class indexExc
{
    int ind;

public:
    indexExc(int val) : ind(val) {}
    const char *what() throw()
    {
        return "Index Out of Bounds Exception";
    }
};
int main()
{
    int size, index;

    cout << "Enter array size: ";
    cin >> size;
    int *array = new int[size];

    cout << "Enter array elements : ";
    for (int i = 0; i < size; i++)
        cin >> array[i];

    try
    {
        cout << "Enter position of element to get : ";
        cin >> index;

        if (index < 1 || index - 1 >= size)
        {
            throw indexExc(index);
        }
        cout << index << "th element : " << array[index - 1] << endl;
    }
    catch (indexExc &ob)
    {
        cout << ob.what() << endl;
    }
    catch (...)
    {
        cout << "Unknown error " << endl;
    }

    return 0;
}