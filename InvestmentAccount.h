/*
* Author: Nicholas Sessa
* Date: February 8, 2022
* 
* InvestmentAccount.h
*/

#pragma once
#ifndef InvestmentAccount_h
#define InvestmentAccount_h
#include <string>

class InvestmentAccount
{

public:
	InvestmentAccount();
	InvestmentAccount(double initialAmount, double annualInterestRate); //monthlyDeposit is 0!
	InvestmentAccount(double initialAmount, double annualInterestRate, double monthlyDeposit);



	InvestmentAccount(double initialAmount, double annualInterestRate, int numberOfYears);
	InvestmentAccount(double initialAmount, double monthlyDeposit, double annualInterestRate, int numberOfYears);

	double calcBalanceWithoutMonthlyDeposit(double initialAmount, double annualInterestRate, int numOfYears);
	double calcBalanceWithMonthlyDeposit(double initialAmount, double monthlyDeposit, double annualInterestRate, int numOfYears);


	double getEndingBalance(int numberOfYears);  //Calculate the ending balance after number of years
	// Use www.calculators.org/savings/monthly.php to test values
	double getInterestEarned(int numberOfYears); //Calculate the interest earned for number of years

	std::string getEndingBalanceFormatted(int numberOfYears);	//Use format and round to get the ending balance as a decimal to 2 places

	/*
	* closing balance = initial deposit
	* 
	loop from 1 month until numberOfYears * 12
		calculate the interest
		sum the closing balance, monthly deposit and interest earned

	after loop, return total
	*/

	/*
	if year is not year one then
		difference between any two consecutive years
		subtract the monthly deposit for 12 months
	else
		difference between ending balance at year 1 and the initial deposit
		subtract the monthly deposit for 12 months
	*/

	std::string getInterestEarnedFormatted(int numberOfYears);  //Use format and round to get the ending balance as a decimal to 2 places

	double getInitialAmount();
	double getMonthlyDeposit();
	double getAnnualInterestRate();
	int getNumberOfYears();

	void setInitialAmount(double initialAmount);
	void setMonthlyDeposit(double monthlyDeposit);
	void setAnnualInterestRate(double annualInterestRate);
	void setNumberOfYears(int numOfYears);

	double round(double value, int places);
	std::string format(double value);

private:
	double m_totalAmount;
	double m_interestAmount;
	double m_initialAmount;
	double m_monthlyDeposit;
	double m_annualInterestRate;
	int m_numberOfYears;
	double m_yearlyTotalInterest;
};

#endif