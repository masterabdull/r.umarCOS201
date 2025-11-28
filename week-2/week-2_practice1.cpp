// my first program in C++
#include <iostream>

using namespace std;

int main()
{
    int radius;

    cout << "Enter radius: " << endl;
    std::cin >> radius;
    int area = 3.142 * radius * radius;
    cout << "The area is : " << area;
}