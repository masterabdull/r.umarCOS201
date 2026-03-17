#include <iostream> 

using namespace std; 
 
// Define max function
int max(int num1, int num2)
{
    int result;
    if (num1 > num2)
        result = num1;
    else
        result = num2;
    return result;
}
 
// The main function
int main()
{
    int i = 5;
    int j = 2;
    int k = max(i, j); // invoke the max function
    cout << "The maximum between " << i << " and " << j << " is " << k << endl;
    return 0;
}