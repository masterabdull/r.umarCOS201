#include <iostream> // Required for cout, cin, and endl
 
using namespace std; // To use cout, cin, and endl directly without std:: prefix
 
// Print grade for the score
void printGrade(double score)
{
    if (score >= 70.0)
    {
        cout << 'A' << endl;
    }
    else if (score >= 60.0)
    {
        cout << 'B' << endl;
    }
    else if (score >= 50.0)
    {
        cout << 'C' << endl;
    }
    else if (score >= 45.0)
    {
        cout << 'D' << endl;
    }
    else
    {
        cout << 'F' << endl;
    }
}
 
// Main function definition
int main()
{
    cout << "Enter a score: ";
    double score;
    cin >> score;
    cout << "The grade is ";
    printGrade(score);
 
    return 0;
}