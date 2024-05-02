#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

long long factorial(int n) {
    if (n < 0) {
        cout << "Error: Negative input\n";
        return 0;
    }

    if (n > 20) {
        cout << "Error: Overflow\n";
        return 0;
    }

    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int num;
    cout << "Enter a non-negative integer: ";
    cin >> num;

    auto start = high_resolution_clock::now();
    long long result = factorial(num);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Factorial of " << num << " is: " << result << endl;
    cout << "Execution time: " << duration.count() << " nanoseconds" << endl;

    return 0;
}