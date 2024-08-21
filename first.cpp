#include <iostream>
#include <cmath>
#include <iomanip>
#include "divisor.h"
#include "multiplier.h"


using namespace std;



int main(){

    const int monthsInYear = 12;
    const int percentDenominator = 100;
    double principal = 0.0;

    cout <<"Enter the principal amount: ";

    cin >> principal;

    double humanInterest = 0.0;

    cout <<"Enter the interest rate: ";

    cin >> humanInterest;

    double interest = divisor(humanInterest, percentDenominator);
    int yearsOfLoan = 0.0;

    cout <<"Enter the years of the loan: ";

    cin >> yearsOfLoan;
    
    double monthInterest = divisor(interest, monthsInYear);
    long monthsOfLoan = multiplier(yearsOfLoan, monthsInYear);

    double payment = 0.0;

    payment = principal * (monthInterest / (1-((double)pow(1 + monthInterest, (double)-monthsOfLoan))));

    cout << "Paymnent: " << setiosflags(ios::fixed) << setprecision(2) << payment << endl;



    return 0;


}