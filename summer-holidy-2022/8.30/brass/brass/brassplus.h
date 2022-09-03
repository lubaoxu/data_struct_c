#pragma once

#include <string>

#include "brass.h"

class BrassPlus :public Brass
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const std::string& s = "Nullbody", long an = -1,
		double bal = 0.0, double ml = 500, double r = 0.11125);
	BrassPlus(const Brass& ba, double ml = 500, double r = 0.11125);

	~BrassPlus();
	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);
	void ReseMax(double m) { maxLoan = m; }
	void ReseRate(double r) { rate = r; };
	void ResetOwes() { owesBank = 0; }

};