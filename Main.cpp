#include "investment.h"

int main() {
    InvestmentCalculator calculator; // Instance of the InvestmentCalculator class
    calculator.menuDisplay(); // Display menu for user input
    calculator.userInput(); // Gather user input 
    calculator.calculateWithoutMonthlyDeposits(); // Calculate investment growth without monthly deposits
    calculator.calculateWithMonthlyDeposits(); // Calculate investment growth with monthly deposits
    return 0; // Indicate successful completion
}
