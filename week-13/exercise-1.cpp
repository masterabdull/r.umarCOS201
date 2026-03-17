#include <iostream>
 
using namespace std;
 
int main() {
    int arr[8] = {15, 23, 7, 42, 10, 30, 5, 28};
    const int array_size = 8;
 
    cout << "Original array elements: ";
    for (int i = 0; i < array_size; ++i) {
        cout << arr[i] << (i == array_size - 1 ? "" : ", ");
    }
    cout << endl;
 
    int max_element = arr[0];
 
    for (int i = 1; i < array_size; ++i) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
    }
    cout << "The largest element in the array is: " << max_element << endl;
 
    int min_element = arr[0];
    int min_index = 0;
 
    for (int i = 1; i < array_size; ++i) {
        if (arr[i] < min_element) {
            min_element = arr[i];
            min_index = i;
        }
    }
    cout << "The smallest element in the array is: " << min_element << endl;
    cout << "The index of the smallest element is: " << min_index << endl;
 
    return 0;
}