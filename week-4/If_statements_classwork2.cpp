#include <iostream>
using namespace std;

int main() {
    int age;

    // Prompt user for input
    cout << "Enter your age: ";
    cin >> age;

    // Check if age is at least 18
    if (age >= 18) {
        cout << "You are an adult" << endl;
    } else {
        cout << "You are NOT an adult" << endl;
    }

    return 0;
}
