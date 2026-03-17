#include <iostream>
using namespace std;
int main() {
  int total = 0;
  int count = 0;
  int positive_count = 0;
  int negative_count = 0;
  while(1 == 1) {
    int  n = 0;
    cout <<"Enter a number (input 0 to stop): ";
    cin >> n;
    if (n < 0) {
        negative_count++;
    }
        else if (n > 0) {
            positive_count++;

    } else {
        break;
    }
  total += n;
    count++;
    



}
double average = static_cast<double>(total) / count;
cout << "Total: " << total << endl;
cout << "Count: " << count << endl;
cout<< "Average: " << average << endl;
cout << "Negative numbers entered: " << negative_count << endl;
cout << "Positive numbers entered: " << positive_count << endl;
}