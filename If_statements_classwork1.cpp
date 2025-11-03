#include <iostream>
using namespace std;

int main() {
    int number;

    // Prompt user for input
    cout << "Enter an integer: ";
    cin >> number;

    // Check if number is a multiple of 5
    if (number % 5 == 0) {
        cout << "HiFive" << endl;
    }

    // Check if number is even
    if (number % 2 == 0) {
        cout << "HiEven" << endl;
    }

    return 0;
}
