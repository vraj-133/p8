#include <iostream>
using namespace std;

double fact(double x) {
    double result = 1;
    for (int i = 2; i <= x; i++)
        result *= i;
    return result;
}

double sumFactn(int n, double (*f)(double)) {
    double sum = 0;
    for (int i = 1; i <= n; i++)
        sum += f(i);
    return sum;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Sum of factorials of first " << n << " numbers = "
         << sumFactn(n, fact) << endl;

    return 0;
}