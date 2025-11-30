#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    string name;
    cout << "Enter your name: " << endl;
    getline(cin, name);

    int jambscore;
    do {
        cout << "Enter your JAMB score: " << endl;
        cin >> jambscore;
        if (jambscore > 400 || jambscore < 0) {
            cout << "ERROR! Invalid JAMB score, please try again." << endl;
        }
    } while (jambscore > 400 || jambscore < 0);

    double waecaverage;
    do {
        cout << "Enter your WAEC average score: " << endl;
        cin >> waecaverage;
        if (waecaverage > 100 || waecaverage < 0) {
            cout << "ERROR! Invalid WAEC average score. Try again." << endl;
        }
    } while (waecaverage > 100 || waecaverage < 0);

    int Age;
    cout << "How old are you? (In years)" << endl;
    cin >> Age;

    bool isPaufirstchoice;
    cout << "Is Pan-Atlantic University your first choice? (1 = Yes, 0 = No) " << endl;
    cin >> isPaufirstchoice;

    bool hasDisciplinaryrecords;
    cout << "Do you have any disciplinary records? (1 = Yes, 0 = No)" << endl;
    cin >> hasDisciplinaryrecords;

    cout << "Which hostel would you prefer to stay in? (1-2) or 3 if you are a day student" << endl;
    cout << "S/N | Hostel           | Price (N)" << endl;
    cout << "1   | Main Hostel      | 180,000.00" << endl;
    cout << "2   | Annex Hostel     | 120,000.00" << endl;
    cout << "3   | Day Student      | 0.00" << endl;

    int hosteloption;
    cin >> hosteloption;

    string hostel;
    int hostelfee;

    switch (hosteloption) {
        case 1:
            hostel = "Main Hostel";
            hostelfee = 180000;
            break;
        case 2:
            hostel = "Annex Hostel";
            hostelfee = 120000;
            break;
        case 3:
            hostel = "Day Student";
            hostelfee = 0;
            break;
        default:
            hostel = "Invalid option";
            hostelfee = 0;
            break;
    }

    const int Basetuition = 1500000;
    string admissionstatus;

    
    if (hasDisciplinaryrecords || Age < 15) {
        admissionstatus = "Your admission has been rejected";
    }
    else if (((jambscore >= 220 && waecaverage >= 60) && isPaufirstchoice) ||
             (jambscore >= 200 && waecaverage >= 70)) {
        admissionstatus = "You have been admitted";
    }
    else {
        admissionstatus = "Your admission is pending";
    }

    // Scholarship calculation
    int scholarshippercent = 0;

    if (jambscore >= 320) scholarshippercent = 30;
    else if (jambscore >= 280) scholarshippercent = 20;
    else if (jambscore >= 240) scholarshippercent = 10;

    if (waecaverage >= 80 && isPaufirstchoice) {
        scholarshippercent += 5;
    }

    // Hostel changes for rejected/pending
    if (admissionstatus == "Your admission is pending" && hasDisciplinaryrecords) {
        hostel = "On Hold";
        hostelfee = 0;
    }
    else if (admissionstatus == "Your admission has been rejected") {
        hostel = "Not applicable";
        hostelfee = 0;
    }

    // Always compute tuition after scholarship
    int tuitionafterscholarship = Basetuition - (scholarshippercent * Basetuition / 100);

    // Random grant only for admitted students
    int grant = 0;
    int r = 0;

    if (admissionstatus == "You have been admitted") {
        srand(time(0));
        r = rand() % 100 + 1;

        bool isPrime = r==2 || r==3 || r==5 || r==7 || r==11 || r==13 || r==17 || r==19 ||
                       r==23 || r==29 || r==31 || r==37 || r==41 || r==43 || r==47 ||
                       r==53 || r==59 || r==61 || r==67 || r==71 || r==73 || r==79 ||
                       r==83 || r==89 || r==97;

        if (isPrime) {
            grant = 50000;
        }
    }

    // Total payable
    int totalpayable = tuitionafterscholarship + hostelfee - grant;
    if (totalpayable < 0) totalpayable = 0;

    // OUTPUT
    cout << "\n===== STUDENT BILLING SUMMARY =====\n";
    cout << "Name: " << name << endl;
    cout << "Admission status: " << admissionstatus << endl;
    cout << "Scholarship: " << scholarshippercent << "%" << endl;
    cout << "Tuition After Scholarship: NGN " << tuitionafterscholarship << endl;
    cout << "Hostel: " << hostel << " | Hostel Fees: NGN " << hostelfee << endl;
    cout << "Random Draw: " << r << " | Merit Grant: NGN " << grant << endl;
    cout << "TOTAL PAYABLE: NGN " << totalpayable << endl;

    return 0;
}
