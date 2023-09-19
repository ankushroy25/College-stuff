#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
public:
    virtual float surfaceArea() = 0;
    virtual float volume() = 0;
};

class Cuboid : public Shape
{
private:
    float length, width, height;

public:
    Cuboid(float l, float w, float h) : length(l), width(w), height(h) {}

    float surfaceArea()
    {
        return 2 * (length * width + width * height + height * length);
    }

    float volume()
    {
        return length * width * height;
    }
};

class Cone : public Shape
{
private:
    float radius, height;

public:
    Cone(float r, float h) : radius(r), height(h) {}

    float surfaceArea()
    {
        float slantHeight = sqrt(radius * radius + height * height);
        return 3.14 * radius * (radius + slantHeight);
    }

    float volume()
    {
        return (1.0 / 3) * 3.14 * radius * radius * height;
    }
};

class Cylinder : public Shape
{
private:
    float radius, height;

public:
    Cylinder(float r, float h) : radius(r), height(h) {}

    float surfaceArea()
    {
        return 2 * 3.14 * radius * (radius + height);
    }

    float volume()
    {
        return 3.14 * radius * radius * height;
    }
};

int main()
{
    Shape *cu = new Cuboid(5, 3, 4);
    Cone co(2, 6);
    Cylinder cy(3, 5);

    cout << "Surface Area: " << cu->surfaceArea() << endl;
    cout << "Volume: " << cu->volume() << endl;
    cout << "---------------------" << endl;
    cout << "Surface Area: " << co.surfaceArea() << endl;
    cout << "Volume: " << co.volume() << endl;
    cout << "---------------------" << endl;
    cout << "Surface Area: " << cy.surfaceArea() << endl;
    cout << "Volume: " << cy.volume() << endl;
    cout << "---------------------" << endl;

    return 0;
}
