#include <iostream>
using namespace std;

bool verifyPin(int correctPin){
    int attempt = 1;
    while(attempt <= 3){
        cout << "Please enter your Personal Identification Number (PIN):" << endl;
        int input;
        cin >> input;

        if(input == correctPin){
            cout << "PIN verified successfully.\n" << endl;
            return true;
        }

        cout << "Incorrect PIN. Attempt " << attempt << " of 3.\n" << endl;
        attempt++;
    }

    cout << "You have exceeded the maximum number of attempts.\n" << endl;
    return false;
}

void displayMenu(){
    cout << "\n========== ATM MAIN MENU ==========" << endl;
    cout << "1. Check Account Balance" << endl;
    cout << "2. Deposit Funds" << endl;
    cout << "3. Withdraw Funds" << endl;
    cout << "4. Reset PIN" << endl;
    cout << "5. Exit" << endl;
    cout << "Please select an option (1-5):" << endl;
}

double viewbalance(double balance){
    cout << "\nYour current account balance is: NGN " << balance << "\n" << endl;
    return balance;
}

double depositMoney(double balance){
    cout << "Enter the amount you wish to deposit: NGN ";
    int depositamount;
    cin >> depositamount;

    cout << "Deposit successful! NGN " << depositamount << " has been added to your account.\n" << endl;

    return depositamount + balance;
}

double withdrawMoney(double balance, double dailyLimit){
    cout << "Enter the amount you would like to withdraw: NGN ";
    int withdrawal;
    cin >> withdrawal;

    if(withdrawal > balance){
        cout << "Transaction declined: Insufficient funds.\n" << endl;
        return balance;
    }
    if(withdrawal > dailyLimit){
        cout << "Transaction declined: Amount exceeds your daily withdrawal limit.\n" << endl;
        return balance;
    }

    cout << "Withdrawal successful! Please take your cash.\n" << endl;
    return balance - withdrawal;
}

int resetPin(int currentPin){
    cout << "\nTo reset your PIN, please enter your current PIN: ";
    int oldpin;
    cin >> oldpin;

    if(oldpin == currentPin){
        cout << "Enter your new PIN: ";
        int newpin;
        cin >> newpin;

        cout << "PIN reset successful.\n" << endl;
        return newpin;
    }
    else{
        cout << "Incorrect current PIN. PIN reset cancelled.\n" << endl;
        return currentPin;
    }
}

int main(){
    int AccountBalance = 50000;
    int Daily_withdrawal_limit = 20000;
    int User_Pin = 4321;

    bool isverified = verifyPin(User_Pin);

    if(!isverified){
        cout << "Your account has been locked for security reasons. Please contact customer support." << endl;
        return 0;
    }

    bool hasexited = false;

    do{
        displayMenu();
        int menuoption;
        cin >> menuoption;

        switch(menuoption){
            case 1:
                viewbalance(AccountBalance);
                break;

            case 2:
                AccountBalance = depositMoney(AccountBalance);
                break;

            case 3:
                AccountBalance = withdrawMoney(AccountBalance, Daily_withdrawal_limit);
                break;

            case 4:
                User_Pin = resetPin(User_Pin);
                break;

            case 5:
                cout << "\nThank you for banking with us. Have a wonderful day!" << endl;
                return 0;

            default:
                cout << "Invalid option selected. Please try again.\n" << endl;
        }

    } while(!hasexited);
}
