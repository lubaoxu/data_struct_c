#include <iostream>
#include <windows.h>

#include "brassplus.h"


int main()
{
	Brass * p = new BrassPlus("Porcelot Pigg", 381299, 4000.00);
	delete p;
	p = NULL;

	::MessageBoxA(NULL, "ssgfdgdsfgdfskgljdsf  g", "", NULL);

	//return 0;  api   application interface

	using std::cout;
	using std::endl;

	Brass Piggy("Porcelot Pigg", 381299, 4000.00);
	Brass Hoggy("Horatio hogg", 382288, 3000.00);
	Piggy.ViewAcct();
	cout << endl;
	Hoggy.ViewAcct();
	cout << endl;
	cout << "Depositing $1000 into the Hogg Account\n";
	Hoggy.Deposit(1000.00);
	cout << "New balance: $" << Hoggy.Balance() << endl;
	cout << "Withdrawing $4200 from the Hogg Accout:\n";
	Hoggy.Withdraw(4200.00);
	Hoggy.ViewAcct();
	return 0;
}