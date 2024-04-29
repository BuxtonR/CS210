//Buxton McCaslin CS-210 Project 2 4/7/2024
#include "investment.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Constructor to initialize variables
InvestmentCalculator::InvestmentCalculator()
    : initialInvestment(0.0), monthlyDeposit(0.0), annualInterestRate(0.0), numberOfYears(0.0) {
}

// Display menu for user input
void InvestmentCalculator::menuDisplay() {
    cout << "********************************\n";
    cout << "********** Data Input **********\n";
    cout << "Initial Investment Amount: \n";
    cout << "Monthly Deposit: \n";
    cout << "Annual Interest: \n";
    cout << "Number of years: \n";
}
void InvestmentCalculator::userInput() {
    cout << "********************************\n";
    cout << "********** Data Input **********\n";

    // Validation for initial investment input
    do {
        cout << "Initial Investment Amount: $";
        cin >> initialInvestment;
        if (initialInvestment <= 0) {
            cout << "Error: Initial investment amount must be positive. Please enter a valid amount.\n";
        }
    } while (initialInvestment <= 0);

    // Validation for monthly deposit input
    do {
        cout << "Monthly Deposit: $";
        cin >> monthlyDeposit;
        if (monthlyDeposit < 0) {
            cout << "Error: Monthly deposit amount cannot be negative. Please enter a valid amount.\n";
        }
    } while (monthlyDeposit < 0);

    // Validation for annual interest rate input
    do {
        cout << "Annual Interest: %";
        cin >> annualInterestRate;
        if (annualInterestRate < 0) {
            cout << "Error: Annual interest rate cannot be negative. Please enter a valid rate.\n";
        }
    } while (annualInterestRate < 0);

    // Validation for number of years input
    do {
        cout << "Number of years: ";
        cin >> numberOfYears;
        if (numberOfYears <= 0) {
            cout << "Error: Number of years must be positive. Please enter a valid number.\n";
        }
    } while (numberOfYears <= 0);
}

// Calculate investment growth without monthly deposits
void InvestmentCalculator::calculateWithoutMonthlyDeposits() {
    float totalAmount = initialInvestment;
    float interestAmount;

    cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
    cout << "==============================================================\n";
    cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
    cout << "--------------------------------------------------------------\n";

    // Rate through each year
    for (int i = 0; i < numberOfYears; i++) {
        interestAmount = totalAmount * (annualInterestRate / 100);
        totalAmount += interestAmount;
        cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t$" << interestAmount << "\n";
    }
}

// Calculate investment growth with monthly deposits
void InvestmentCalculator::calculateWithMonthlyDeposits() {
    float totalAmount = initialInvestment;
    float interestAmount;
    float yearTotalInterest;

    cout << "\n\nBalance and Interest With Additional Monthly Deposits\n";
    cout << "==============================================================\n";
    cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
    cout << "--------------------------------------------------------------\n";

    // Rate through each year
    for (int i = 0; i < numberOfYears; i++) {
        yearTotalInterest = 0;
        // Rate through each month
        for (int j = 0; j < 12; j++) {
            interestAmount = (totalAmount + monthlyDeposit) * (annualInterestRate / 100 / 12);
            yearTotalInterest += interestAmount;
            totalAmount += monthlyDeposit + interestAmount;
        }
        // Print year end balance and the earned interest
        cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t$" << yearTotalInterest << "\n";
    }
}
