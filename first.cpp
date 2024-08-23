#include <iostream>
#include <cmath>
#include <iomanip>
#include "divisor.h"
#include "multiplier.h"
#include "globals.h"


using namespace std;



int main(){

    double principal = 0.0;

    cout <<"Enter the principal amount: ";

    cin >> principal;

    double humanInterest = 0.0;

    cout <<"Enter the interest rate: ";

    cin >> humanInterest;

    double interest = divisor(humanInterest, gPercentDenominator);
    int yearsOfLoan = 0.0;

    cout <<"Enter the years of the loan: ";

    cin >> yearsOfLoan;
    
    double monthInterest = divisor(interest, gMonthsInYear);
    long monthsOfLoan = multiplier(yearsOfLoan, gMonthsInYear);

    double payment = 0.0;

    payment = principal * (monthInterest / (1-((double)pow(1 + monthInterest, (double)-monthsOfLoan))));

    cout << "Paymnent: " << setiosflags(ios::fixed) << setprecision(2) << payment << endl;

    double currInterestPayment = 0.0;
    double currPrincipalPayment = 0.0;
    double currBalance = 0.0;

    currBalance = principal; 

    long currLoanMonth = 1;

    while(currLoanMonth <= monthsOfLoan){

        gAmortizeMonth amortMonth;

        currInterestPayment = currBalance * monthInterest;
        currPrincipalPayment = payment - currInterestPayment;
        currBalance = currBalance - currPrincipalPayment;

        amortMonth.year = 1;
        amortMonth.yearMonth = 1;
        amortMonth.loanMonth = currLoanMonth;
        amortMonth.payment = payment;
        amortMonth.pureInterest = currInterestPayment;
        amortMonth.paidDownPrincipal = currPrincipalPayment;
        amortMonth.principalBalance = currBalance;

        struct gAmortizeMonth{
            int year;
            int yearMonth;
            long loanMonth;
            double payment;
            double pureInterest;
            double paidDownPrincipal;
            double principalBalance;
        };
        
        cout << "Current Month: " << amortMonth.loanMonth 
        << " Principal Paid: " << amortMonth.paidDownPrincipal 
        << " Interest Paid: " << amortMonth.pureInterest
        << " Balance: " << amortMonth.principalBalance << endl;
        
        currLoanMonth++;
    }

    cout << "Loan payments complete." << endl;



    return 0;


}