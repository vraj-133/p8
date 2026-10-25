#include <iostream>
using namespace std;

class matrix
{
private:
    int m[3][3];

public:
    void read()
    {
        cout << "Enter 9 elements (row by row):" << endl;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cin >> m[i][j];
    }

    void print()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                cout << m[i][j] << "\t";
            cout << endl;
        }
    }

    matrix transpose()
    {
        matrix t;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                t.m[j][i] = m[i][j];
        return t;
    }

    matrix operator + (const matrix &b)
    {
        matrix result;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                result.m[i][j] = m[i][j] + b.m[i][j];
        return result;
    }

    matrix operator - (const matrix &b)
    {
        matrix result;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                result.m[i][j] = m[i][j] - b.m[i][j];
        return result;
    }
};

int main()
{
    matrix a, b;

    cout << "Enter first matrix:" << endl;
    a.read();
    cout << "Enter second matrix:" << endl;
    b.read();

    cout << "\nFirst matrix:" << endl;
    a.print();
    cout << "\nSecond matrix:" << endl;
    b.print();

    cout << "\nTranspose of first matrix:" << endl;
    matrix t = a.transpose();
    t.print();

    cout << "\nSum of matrices:" << endl;
    matrix sum = a + b;
    sum.print();

    cout << "\nDifference of matrices (first - second):" << endl;
    matrix diff = a - b;
    diff.print();

    return 0;
}