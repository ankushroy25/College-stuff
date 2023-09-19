#include <iostream>
using namespace std;

class student
{
    string Name;
    int Roll;
    int Marks[3];

public:
    student() {}
    student(string name, int roll, int marks[])
    {
        Name = name;
        Roll = roll;
        for (int i = 0; i < 3; i++)
            Marks[i] = marks[i];
    }
    int getTotalMarks()
    {
        int total = 0;
        for (int i = 0; i < 3; i++)
        {
            total += Marks[i];
        }
        return total;
    }
    float getAvgMarks()
    {
        return getTotalMarks() / 3;
    }
    void display()
    {
        cout << "Name : " << Name << endl;
        cout << "Roll : " << Roll << endl;
        cout << "Marks:- " << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << Marks[i] << ", ";
        }
    }
};
void topper(student students[])
{
    int total, max = 0, top;
    for (int i = 0; i < 5; i++)
    {
        total = students[i].getTotalMarks();

        if (total > max)
        {
            max = total;
            top = i;
        }
    }
    cout << "-: Topper :- \n";
    students[top].display();
}
void input(student students[])
{
    int roll;
    string name;
    int marks[3];

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter Roll: ";
        cin >> roll;
        cout << "Enter marks " << endl;
        for (int j = 0; j < 3; j++)
        {
            cin >> marks[j];
        }

        students[i] = student(name, roll, marks);
    }
}
int main()
{
    student students[5];
    input(students);
    topper(students);
}
