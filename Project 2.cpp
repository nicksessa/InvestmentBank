/*
* Author: Nicholas Sessa
* Date: February 8, 2022
*
* Project 2.cpp
*/

#include <iostream>
#include <iomanip>
#include "InvestmentAccount.h"

using namespace std;


//Main Class function prototypes
void displayOutput(InvestmentAccount account, int numberOfYears);    //Displays the account details, as well as account balances and interest earned for each year.

InvestmentAccount theInvestment;

double initialInvestment;
double monthlyDeposit;
double annualInterest;
double months;
int years;
char userInput = 'a';
void displayMenu();
void displayDataInputHeader();
void getInitialInvestmentInput();
void getMonthlyDepositInput();
void getAnnualInterestInput();
void getNumberOfYearsInput();
int validateInt();
double validateDouble();


int main()
{
    //Get the input...validate that the values are non-negative.
	while (userInput != 'q') {
		system("CLS");
		displayMenu();

		//Create two InvestmentAccount variables...one with monthly deposit and one without monthly deposit
		theInvestment.calcBalanceWithoutMonthlyDeposit(initialInvestment, annualInterest, years);
		theInvestment.calcBalanceWithMonthlyDeposit(initialInvestment, monthlyDeposit, annualInterest, years);

		cout << "Please enter 'q' to quit. Press any other key to continue. ";
		cin >> userInput;
	}

    //Display the output for each investment account

	return 0;
}

void displayMenu() {
	displayDataInputHeader();
	getInitialInvestmentInput();
	getMonthlyDepositInput();
	getAnnualInterestInput();
	getNumberOfYearsInput();
}

void displayDataInputHeader() {
	cout << "**********************************" << endl;
	cout << "********** Data Input ************" << endl;
}

void getInitialInvestmentInput() {
	try {
		cout << "Initial Investment Amount: $";
		initialInvestment = validateDouble();
		if (initialInvestment < 0) {
			throw runtime_error("Invalid entry.");
		}
		theInvestment.setInitialAmount(initialInvestment);
	}
	// Displays error to user and prompts the user again
	catch (runtime_error& excpt) {
		cout << excpt.what() << endl;
		cout << "Initial Investment Amount cannot be less than zero." << endl;
		//system("PAUSE");
		getInitialInvestmentInput();
	}
}

void getMonthlyDepositInput() {
	try {
		cout << "Monthly Deposit: $";
		monthlyDeposit = validateDouble();
		if (monthlyDeposit < 0) {
			throw runtime_error("Invalid entry.");
		}
		theInvestment.setMonthlyDeposit(monthlyDeposit);
	}
	// Displays error to user and prompts the user again
	catch (runtime_error& excpt) {
		cout << excpt.what() << endl;
		cout << "Monthly Deposit cannot be less than zero." << endl;
		system("PAUSE");
		getMonthlyDepositInput();
	}
}

void getAnnualInterestInput() {
	try {
		cout << "Annual Interest: %";
		annualInterest = validateDouble();;
		if (annualInterest < 0) {
			throw runtime_error("Invalid entry.");
		}
		theInvestment.setAnnualInterestRate(annualInterest);
	}
	
	// Displays error to user and prompts the user again
	catch (runtime_error& excpt) {
		cout << excpt.what() << endl;
		cout << "Annual Interest cannot be less than zero." << endl;
		system("PAUSE");
		getAnnualInterestInput();
	}
}

void getNumberOfYearsInput() {
	try {
		cout << "Number of years: ";
		years = validateInt();
		if (years <= 0) {
			throw runtime_error("Invalid entry.");
		}
		theInvestment.setNumberOfYears(years);
	}

	// Displays error to user and prompts the user again
	catch (runtime_error& excpt) {
		cout << excpt.what() << endl;
		cout << "Years cannot be less than zero." << endl;
		system("PAUSE");
		getNumberOfYearsInput();
	}
}

static double validateDouble() {
	double userInputDouble;
	bool badData = true;

	while (badData) {
		if (cin >> userInputDouble) {
			badData = false;
			break;
		}
		else {
			cout << "Invalid data!" << endl;
			cout << "Enter a valid value: ";
			cin.clear();
			while (cin.get() != '\n');
		}
	}
	return userInputDouble;
}

static int validateInt() {
	int userInputInt;
	bool badData = true;

	while (badData) {
		if (cin >> userInputInt) {
			badData = false;
			break;
		}
		else {
			cout << "Invalid data!" << endl;
			cout << "Enter a valid value: ";
			cin.clear();
			while (cin.get() != '\n');
		}
	}

	return userInputInt;
}