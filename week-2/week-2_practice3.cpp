#include "iostream"

using namespace std;

int main(){
    int T ;
    cout << "Enter T:" << endl;
    cin >> T;

    int M ;
    cout << "Enter M:" << endl;
    cin >> M ;

    int temp;
    temp = T;
    T = M;
    M = temp;
    cout << "The new value of T is " << T << endl;
    cout << "The new value of M is " << M << endl;
    
}