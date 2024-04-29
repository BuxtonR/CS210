#ifndef INVESTMENT_H
#define INVESTMENT_H

class InvestmentCalculator {
public:
    InvestmentCalculator(); // Constructor declaration
    void userInput(); // Function to take user input
    void menuDisplay(); // Function to display menu
    void calculateWithoutMonthlyDeposits(); // Function to calculate balance without monthly deposits
    void calculateWithMonthlyDeposits(); // Function to calculate balance with monthly deposits
private:
    float initialInvestment; // Initial investment amount
    float monthlyDeposit; // Monthly deposit amount
    float annualInterestRate; // Annual interest rate
    float numberOfYears; // Number of years
};

#endif
