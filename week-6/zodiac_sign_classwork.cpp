#include <iostream>
using namespace std;
int main()
{
    int year;
    cout << "Enter your birth year:";
    cin >> year;
    switch (year % 12)
    {
    case 0:
        cout << "Year of the Monkey";
        break;
    case 1:
        cout << "Year of the Rooster";
        break;
    case 2:
        cout << "Year of the Dog";
        break;
    case 3:
        cout << "Year of the Pig";
        break;
    case 4:
        cout << "Year of the Rat";
        break;
    case 5:
        cout << "Year of the Ox";
        break;
    case 6:
        cout << "Year of the Tiger";
        break;
    case 7:
        cout << "Year of the Rabbit";
        break;
    case 8:
        cout << "Year of the Dragon";
        break;
    case 9:
        cout << "Year of the Snake";
        break;
    case 10:
        cout << "Year of the Horse";
        break;
    case 11:
        cout << "Year of the Sheep";
        break;
    }
}