#include <iostream>
#include <chrono> // for measuring runtime
using namespace std;
using namespace std::chrono;

long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num < 0) {
        cout << "Factorial isn't defined for negative numbers." << endl;
    } else {
        auto start = high_resolution_clock::now(); // start measuring time
        long long fact = factorial(num);
        auto stop = high_resolution_clock::now(); // stop measuring time

        auto duration = duration_cast<nanoseconds>(stop - start); // calculate duration in nanoseconds

        cout << "Factorial of " << num << " is: " << fact << endl;
        cout << "Calculation time: " << duration.count() << " nanoseconds" << endl;
    }

    return 0;
}