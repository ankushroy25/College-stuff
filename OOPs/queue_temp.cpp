#include <iostream>
#include <string>
#define MAX 5
using namespace std;

namespace dsa
{
    template <class Q>
    class queue
    {
        Q *arr;
        int front, rear, size;

    public:
        queue()
        {
            arr = new Q[MAX];
            front = rear = -1;
            size = 0;
            cout << "Constructor" << endl;
        }
        void enqueue(Q val)
        {
            if (size == MAX)
                cout << "Queue is full" << endl;
            else
            {
                rear = (rear + 1) % MAX;
                arr[rear] = val;
                ++size;
                if (front == -1)
                    ++front;
            }
        }
        void dequeue()
        {
            if (size == 0)
            {
                front = rear = -1;
                cout << "Queue already empty" << endl;
            }
            else
            {
                --size;
                front = (front + 1) % MAX;
            }
        }
        void display()
        {
            if (size == 0)
            {
                cout << "Queue empty" << endl;
                return;
            }

            cout << "------------------\n|  ";
            int i = front;
            while (i != rear)
            {
                cout << arr[i] << ", ";
                i = (i + 1) % MAX;
            }
            cout << arr[rear] << ", ";
            cout << "\n------------------" << endl;
        }
        ~queue()
        {
            cout << "Destructor " << endl;
        }
    };

}
using namespace dsa;
string datatype(string s)
{
    bool isInteger = false;
    bool isFloat = false;

    for (char ch : s)
    {
        if (isdigit(ch))
            isInteger = true;
        if (isInteger && ch == '.')
            isFloat = true;
    }

    if (isFloat)
        return "FLOAT";
    else if (isInteger)
        return "INTEGER";
    else if (s.length() == 1)
        return "CHAR";

    return "STRING";
}

template <typename T>
void queueOperations(queue<T> *que)
{
    T input;
    int ch;
    do
    {
        cout << "\tMENU \n1 - Enqueue \n2 - Dequeue \n3 - Display \n4 - Exit \n>Enter choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter your input : ";
            cin >> input;
            que->enqueue(input);
            break;
        case 2:
            que->dequeue();
            break;
        case 3:
            que->display();
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (ch != 4);
}

int main()
{

    string input, inputType;
    int ch, flag = 0;

    cout << "Enter a sample data : ";
    cin >> input;
    inputType = datatype(input);
    cout << "Type : " << inputType << endl;

    if (inputType == "INTEGER")
    {
        queue<int> que;
        queueOperations(&que);
    }
    else if (inputType == "FLOAT")
    {
        queue<float> que;
        queueOperations(&que);
    }
    else if (inputType == "CHAR")
    {
        queue<char> que;
        queueOperations(&que);
    }
    else
    {
        queue<string> que;
        queueOperations(&que);
    }

    cout << "Program exit \n--------------" << endl;
    return 0;
}
