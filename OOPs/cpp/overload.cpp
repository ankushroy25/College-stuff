#include <iostream>
using namespace std;
float area(int x, int y)
{
    return x * y;
}
float area(int a)
{
    return a * a;
}
float area(float r)
{
    return 3.1457 * r * r;
}

float input()
{
    float ans;
    int choice;
    cout << "1.Square \n2.Rectangle \n3.Circle \n4.Exit \nEnter choice" << endl;
    cin >> choice;
    if (choice == 4)
        exit(0);

    switch (choice)
    {
    case 1:
        int side;
        cout << "enter side length : ";
        cin >> side;
        ans = area(side);
        break;
    case 2:
        int length, breadth;
        cout << "enter length and breadth : ";
        cin >> length >> breadth;
        ans = area(length, breadth);
        break;
    case 3:
        float radius;
        cout << "enter radius : " << endl;
        cin >> radius;
        ans = area(radius);
        break;
    default:
        cout << "Invalid choice" << endl;
    }
    return ans;
}
void printArea(float ans)
{
    cout << "Area = " << ans << endl;
}

int main()
{
    int choice;
    float ans;
    while (1)
    {
        ans = input();
        printArea(ans);
    }
}