#include <iostream>
using namespace std;

class complex
{
public:
    double r, i;

    complex(double real = 0, double imag = 0)
    {
        r = real;
        i = imag;
    }

    complex(const complex &c)
    {
        r = c.r;
        i = c.i;
    }

    complex operator + (const complex &c)
    {
        complex temp;
        temp.r = r + c.r;
        temp.i = i + c.i;
        return temp;
    }

    complex operator - (const complex &c)
    {
        complex temp;
        temp.r = r - c.r;
        temp.i = i - c.i;
        return temp;
    }

    complex operator * ()
    {
        complex temp;
        temp.r = r;
        temp.i = -i;
        return temp;
    }
};

istream& operator >> (istream &in, complex &c)
{
    cout << "Enter real part: ";
    in >> c.r;
    cout << "Enter imaginary part: ";
    in >> c.i;
    return in;
}

ostream& operator << (ostream &out, const complex &c)
{
    if (c.i >= 0)
        out << c.r << " + " << c.i << "i";
    else
        out << c.r << " - " << -c.i << "i";
    return out;
}

int main()
{
    complex c1, c2;
    cout << "Enter first complex number:" << endl;
    cin >> c1;
    cout << "Enter second complex number:" << endl;
    cin >> c2;

    complex sum = c1 + c2;
    complex diff = c1 - c2;
    complex conj1 = *c1;
    complex c3 = c1;
    complex c4;

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "Sum = " << sum << endl;
    cout << "Difference = " << diff << endl;
    cout << "Conjugate of c1 = " << conj1 << endl;
    cout << "c3 (copy of c1) = " << c3 << endl;
    cout << "c4 (default) = " << c4 << endl;

    return 0;
}