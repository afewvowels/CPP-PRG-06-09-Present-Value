//
//  main.cpp
//  PRG-6-9-Present-Value
//
//  Created by Keith Smith on 10/7/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Suppose you want to deposit a certain amount of money into a savings account and
//  then leave it alone to draw interest for the next 10 years. At the end of 10 years, you
//  would like it to have $10,000 in the account. How much do you need to deposit today to
//  make that happen? You can use the following formula, which is known as the present
//  value formula, to find out:
//
//  P = F / (1 + r)^n
//
//  The terms in the formula are as follows:
//
//  * P is the present value, or the amount that you need to deposit today
//  * F is the future value that you want in the account. (In this case, F is $10,000.)
//  * r is the annual interest rate
//  * n is the number of years that you plan to let the money sit in the account
//
//  Write a program that has a function named presentValue that performs this calculation.
//  The function should accept the future value, annual interest rate, and number of
//  years as arguments. It should return the present value, which is the amount that you
//  need to deposit today. Demonstrate the function in a program that lets the user experiment
//  with different values for the formula's terms.

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float presentValue(float, float);

// Declare global variables instead of passing values around
float const FLT_NUMBER_OF_YEARS = 10.0f;

float fltFutureValue,
      fltAnnualInterestRate,
      fltPresentValue;

int main()
{
    cout << "How much would you like you account\n"
    << "to have in the future?\n";
    cin >> fltFutureValue;
    
    while(!cin || fltFutureValue <= 0.0f)
    {
        cout << "Please enter a positive value for future value:\n";
        cin.clear();
        cin.ignore();
        cin >> fltFutureValue;
    }
    
    cout << "What interest rate do you have on your account?\n";
    cin >> fltAnnualInterestRate;
    
    while(!cin || fltAnnualInterestRate < 0 || fltAnnualInterestRate > 100)
    {
        cout << "Please enter a valid whole number for your interest rate:\n";
        cin.clear();
        cin.ignore();
        cin >> fltAnnualInterestRate;
    }
    
    fltPresentValue = presentValue(fltFutureValue, fltAnnualInterestRate);
    
    cout << setprecision(2) << fixed << showpoint;
    
    cout << "You will need to have $" << fltPresentValue << " in your bank account today.\n";
    
    return 0;
}

float presentValue(float fltFutureValue, float fltAnnualInterestRate)
{
    float fltAnnualInterestRateAdjusted;
    
    fltAnnualInterestRateAdjusted = (fltAnnualInterestRate / 100.0f) + 1.0f;
    
    fltPresentValue = (fltFutureValue) / pow(fltAnnualInterestRateAdjusted, FLT_NUMBER_OF_YEARS);
    
    return fltPresentValue;
}

