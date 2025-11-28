#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
int main()

{
    string name;
    int course;
    int location;
    bool isPauStudent;
    cout << "Hi!, Please enter your full name :) ==> \n";
    getline(cin, name);

    cout << "Are you a Pan Atlantic University student? (1 for true, 0 for false)";
    int flag;
    cin>> flag;
    isPauStudent = (flag != 0);
    cout<<"Enter course (1-5): \n << 1 -- Photography \n  2 -- Painting\n 3 -- Fish Farming \n 4 -- Baking \n 5-- Public Speaking \n";
    cin>>course;
     cout<<"Enter location (1-5): \n << 1 -- Camp House A \n  2 -- Camp House B \n 3 -- Camp House C \n 4 -- Camp House D \n 5-- Camp House E \n";
    cin>>location;

    string courseName;
    int days = 0;
    double regFee = 0.0;
    if (course == 1){
        courseName = "Photography";
        days = 3;
        regFee = 100000;



    }
    else if  (course == 2){
        courseName = "Painting";
        days = 5;
        regFee = 8000;
        


    }
      else if  (course == 3){
        courseName = "Fish Farming";
        days = 7;
        regFee = 15000;
        

    }
      else if  (course == 4){
        courseName = "Baking";
        days = 5;
        regFee = 13000;
        

        
    }
      else if  (course == 5){
        courseName = "Public Speaking";
        days = 2;
        regFee = 5000;
        

    }
    else {
    cout<<"Invalid course selection \n";
    return 1;
    } 
    //Location code
    string LocName;
    double logingPerDay = 0.0;

    if (location == 1){
    LocName = "CampHouse A ";
    logingPerDay = 10000;
    }
     else if (location == 2){
    LocName = "CampHouse B ";
    logingPerDay = 2500;
    }
    else if (location == 3){
    LocName = "CampHouse C ";
    logingPerDay = 5000;
    }
   else if (location == 4){
    LocName = "CampHouse D";
    logingPerDay = 13000;
   }
    else if (location == 5){
    LocName = "CampHouse E ";
    logingPerDay = 5000;
    }
    
else {
    cout<<"Invalid Location selection \n";
    return 1;
}

//computing
double lodgingcost = logingPerDay * days;
double lodgingDiscount = 0.0;
double regDiscount = 0.03 * regFee;
if (isPauStudent && (location == 1 || location ==2)){
    lodgingDiscount = 0.05 * lodgingcost;

}
double lodgingcostAfter = lodgingcost - lodgingDiscount;
if((days> 5) || (regFee > 12000)){
    regDiscount = 0.03 * regFee;
}
double regDiscountAfter = regFee - regDiscount;

srand(time(0));
int r = (rand()%100)+ 1 ;
double promo = 0.0;
if (r==7 || r== 77){
    promo = 500.0;
}
double total = regDiscountAfter + lodgingcostAfter;


cout<<"Name:" <<name;
cout<<"Pau student:   " <<(isPauStudent ? "YES"  : "NO")<< "\n";
cout<<"Course:  "<<courseName<< "\n";
cout<<"Registration Fee: " <<regFee<<"\n";
cout<<"Location: " <<LocName<<"\n";
cout<<"Loging Fee per Day " <<logingPerDay<<"\n";
cout<<"Total lodging cost: " <<lodgingcost<<"\n";
cout<<"Promo: " <<r<<"\n";

cout<<"==============================================================";
cout<<"Total Fee :" <<total<<"\n";

     

     


    return 0;
}