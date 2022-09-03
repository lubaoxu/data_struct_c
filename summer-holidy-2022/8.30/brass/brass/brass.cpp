#include <iostream>

#include "brass.h"

Brass::Brass(const string& s, long an, double bal)
{
	fullName = s;
	acctNum = an;
	balance = bal;
}

Brass::~Brass()
{
	std::cout << " ~Brass() " << std::endl;
}

void Brass::Deposit(double amt)
{
	if (amt < 0)
		cout << "Negative deposit not allowed;"
		<< "deposit is cancelled.\n";
	else
		balance += amt;
}

void Brass::Withdraw(double amt)
{
	format initialState = setFormat();
	precis prec = cout.precision(2);
	if (amt < 0)
		cout << "Withdrawal amout must be positive;"
		<< "withdrawal canceled.\n";
	else if (amt <= balance)
		balance -= amt;
	else
		cout << "Withdrawal amout of $" << amt
		<< "exceeds your balance.\n"
		<< "Withdrawal canceled.\n";
	restore(initialState, prec);
}

double Brass::Balance()const
{
	return balance;
}

void Brass::ViewAcct()const
{
	format initialState = setFormat();
	precis prec = cout.precision(2);
	cout << "Client:" << fullName << endl;
	cout << "Account Number:" << acctNum << endl;
	cout << "Balance: $" << balance << endl;
	restore(initialState, prec);
}


format setFormat()
{
	return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p)
{
	cout.setf(f, std::ios_base::floatfield);
	cout.precision(p);
}


