#include <iostream>
using namespace std;

class Room
{
private:
    float length, breadth, height;

public:
    Room()
    {
        length = 1;
        breadth = 1;
        height = 1;
        cout << "A unit room is built" << endl;
    }

    Room(float l, float b, float h)
    {
        length = l;
        breadth = b;
        height = h;
        cout << "A customized room is built" << endl;
    }

    ~Room()
    {
        cout << "Room of dimensions " << length << ", " << breadth
             << ", " << height << " is demolished" << endl;
    }

    float area()
    {
        return length * breadth;
    }

    float volume()
    {
        return length * breadth * height;
    }
};

int main()
{
    cout << "--- Creating a default (unit) room ---" << endl;
    Room r1;
    cout << "Area = " << r1.area() << ", Volume = " << r1.volume() << endl;

    cout << "\n--- Creating a customized room ---" << endl;
    float l, b, h;
    cout << "Enter length, breadth, height: ";
    cin >> l >> b >> h;
    Room r2(l, b, h);
    cout << "Area = " << r2.area() << ", Volume = " << r2.volume() << endl;

    cout << "\n--- End of main: destructors fire automatically ---" << endl;
    return 0;
}