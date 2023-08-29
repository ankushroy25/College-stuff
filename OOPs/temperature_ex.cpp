#include <iostream>
#include <string>
using namespace std;
class TooHot
{
    float temp;

public:
    TooHot(float t) : temp(t) {}

    const char *what() const throw()
    {
        return ("Temperature is Too Hot");
    }
};

class TooCold
{
    float temp;

public:
    TooCold(float t) : temp(t) {}

    const char *what() const throw()
    {
        return ("Temperature is Too Cold");
    }
};

void checkTemperature(float temperature)
{
    try
    {
        if (temperature > 40)
        {
            throw TooHot(temperature);
        }
        else if (temperature < 20)
        {
            throw TooCold(temperature);
        }
        else
        {
            cout << "Temperature " << temperature << endl;
        }
    }
    catch (TooHot &hotEx)
    {
        cout << hotEx.what() << endl;
    }
    catch (TooCold &coldEx)
    {
        cout << coldEx.what() << endl;
    }
}

int main()
{
    float input;
    cout << "Enter the temperature: ";
    cin >> input;
    checkTemperature(input);
    return 0;
}
