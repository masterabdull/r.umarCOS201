#include <iostream>
using namespace std;

int main() {
    double totalPurchase, salesTax, totalAmount;

    cout << "Enter total purchase amount: ";
    cin >> totalPurchase;

    salesTax = totalPurchase * 0.06;
    totalAmount = totalPurchase + salesTax;

    cout << "Sales tax (6%) = " << salesTax << endl;
    cout << "Total amount including tax = " << totalAmount << endl;

    return 0;
}