#include <iostream>
using namespace std;

void transpose(double** A, const int n) {
    cout << "Transpose of the matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[j][i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;

    double** A = new double*[n];
    for (int i = 0; i < n; i++)
        A[i] = new double[n];

    cout << "Enter " << n * n << " elements (row by row):\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> A[i][j];
        }
    }

    transpose(A, n);
    
    for (int i = 0; i < n; i++)
        delete[] A[i];
    delete[] A;

    return 0;
}