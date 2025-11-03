#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()

using namespace std;

int main() {
    // Step 1: Generate two single-digit random integers (0–9)
    srand(time(0));  // seed the random number generator
    int number1 = rand() % 10;  // generates a number between 0 and 9
    int number2 = rand() % 10;

    // Step 2: If number1 < number2, swap them
    if (number1 < number2) {
        int temp = number1;
        number1 = number2;
        number2 = temp;
    }


    cout << "What is " << number1 << " - " << number2 << "? ";
    int answer;
    cin >> answer;

   
    if (answer == number1 - number2)
        cout << "Correct! " << endl;
    else
        cout << "Incorrect. The correct answer is " << (number1 - number2) << "." << endl;

    return 0;
}