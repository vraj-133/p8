#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size n: ";
    cin >> n;
    int* A = new int[n];
    double** B = new double*[n];
    for (int i = 0; i < n; i++)
        B[i] = new double[n];

    cout << "\nEnter " << n << " integers for array A:\n";
    for (int i = 0; i < n; i++)
        cin >> *(A + i);

    cout << "\nEnter " << n * n << " values for matrix B (row by row):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> *(*(B + i) + j);

    cout << "\nArray A (address : value):\n";
    for (int i = 0; i < n; i++)
        cout << (A + i) << " : " << *(A + i) << "\n";

    cout << "\nMatrix B (address : value):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << (*(B + i) + j) << " : " << *(*(B + i) + j) << "    ";
        cout << "\n";
    }

    delete[] A;
    for (int i = 0; i < n; i++)
        delete[] B[i];
    delete[] B;
    return 0;
}