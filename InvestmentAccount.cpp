/*
* Author: Nicholas Sessa
* Date: February 8, 2022
*
* InvestmentAccount.cpp
*/

#include "InvestmentAccount.h"
#include <iostream>
#include <iomanip>

using namespace std;

//Implementation for InvestmentAccount

// Getters

double InvestmentAccount::getInitialAmount() {
	return m_initialAmount;
}
double InvestmentAccount::getMonthlyDeposit() {
	return m_monthlyDeposit;
}
double InvestmentAccount::getAnnualInterestRate() {
	return m_annualInterestRate;
}
int InvestmentAccount::getNumberOfYears() {
	return m_numberOfYears;
}

// Setters
void InvestmentAccount::setInitialAmount(double initialAmount) {
	m_initialAmount = initialAmount;
}
void InvestmentAccount::setMonthlyDeposit(double monthlyDeposit) {
	m_monthlyDeposit = monthlyDeposit;
}
void InvestmentAccount::setAnnualInterestRate(double annualInterestRate) {
	m_annualInterestRate = annualInterestRate;
}
void InvestmentAccount::setNumberOfYears(int numOfYears) {
	m_numberOfYears = numOfYears;
}

InvestmentAccount::InvestmentAccount() {};

InvestmentAccount::InvestmentAccount(double initialAmount, double annualInterestRate, int numOfYears) {
	m_initialAmount = initialAmount;
	//m_monthlyDeposit = monthlyDeposit;
	m_annualInterestRate = annualInterestRate;
	m_numberOfYears = numOfYears;
	m_interestAmount = 0.0;
	m_totalAmount = 0.0;
};

InvestmentAccount::InvestmentAccount(double initialAmount, double monthlyDeposit, double annualInterestRate, int numOfYears) {
	m_initialAmount = initialAmount;
	m_monthlyDeposit = monthlyDeposit;
	m_annualInterestRate = annualInterestRate;
	m_numberOfYears = numOfYears;
	m_interestAmount = 0.0;
	m_totalAmount = 0.0;
};

double InvestmentAccount::calcBalanceWithoutMonthlyDeposit(double initialAmount, double annualInterestRate, int numOfYears) {
	m_totalAmount = initialAmount;

	// Display table heading
	cout << endl << "     Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << std::string(66, '=') << endl;
	cout << "Year          Year End Balance          Year End Earned Interest" << endl;
	cout << std::string(66, '-') << endl;

	//Calculate yearly interest and year end total
	for (int i = 0; i < numOfYears; i++) {
		m_interestAmount = m_totalAmount * (annualInterestRate / 100);
		m_totalAmount = m_totalAmount + m_interestAmount;
		cout << " " << left << setw(5) << (i + 1) << "\t\t$" << fixed << setprecision(2) << m_totalAmount << "\t\t\t\t$" << m_interestAmount << endl;
	}

	return m_totalAmount;
}

double InvestmentAccount::calcBalanceWithMonthlyDeposit(double initialAmount, double monthlyDeposit, double annualInterestRate, int numOfYears) {
	m_totalAmount = initialAmount;

	// Display table heading
	cout << endl << "     Balance and Interest With Additional Monthly Deposits" << endl;
	cout << std::string(66, '=') << endl;
	cout << "Year          Year End Balance          Year End Earned Interest" << endl;
	cout << std::string(66, '-') << endl;

	// Calculate yearly interest and year end total
	for (int i = 0; i < numOfYears; i++) {
		m_yearlyTotalInterest = 0;

		for (int j = 0; j < 12; j++) {
			m_interestAmount = (m_totalAmount + monthlyDeposit) * ((annualInterestRate / 100.00) / 12.00);
			m_yearlyTotalInterest = m_yearlyTotalInterest + m_interestAmount;
			m_totalAmount = m_totalAmount + monthlyDeposit + m_interestAmount;
		}

		cout << " " << left << setw(5) << (i + 1) << "\t\t$" << fixed << setprecision(2) << m_totalAmount << "\t\t\t\t$" << m_yearlyTotalInterest << endl;
	}

	return m_totalAmount;
}




//The following method rounds a value to the specified number of places.
//NOTE: It works for most values...but is not guaranteed to work for all values!
//@param value - the value to round
//@param places - the number of places to round
//@returns - the rounded number
double InvestmentAccount::round(double value, int places) {
	const int multiplier = pow(10, places);

	double roundedValue = (int)(value * multiplier + 0.5);
	roundedValue = (double)roundedValue / multiplier;
	return roundedValue;
}

//Formats a double value for output purposes.
//This method will not append with any 0s...so the value should be rounded prior to use.
//@param value - the value to format
//@returns - the formatted value.
std::string InvestmentAccount::format(double value) {
	std::string valueAsString = std::to_string(value);
	std::string formatted;

	bool decimalFound = false;
	int decimalCount = 0;

	int i;
	for (i = 0; i < valueAsString.size(); i++) {
		char currentChar = valueAsString[i];

		if (decimalCount == 2) {
			break;
		}

		if (currentChar == '.') {
			decimalFound = true;
		}
		else if (decimalFound && decimalCount != 2) {
			decimalCount++;
		}

		formatted.append(std::string(1, currentChar));
	}

	return formatted;
}