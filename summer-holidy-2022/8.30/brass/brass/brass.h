#ifndef BRASS_H_
#define BRASS_H_

using namespace std;

using std::cout;
using std::endl;
using std::string;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;

class Brass
{
private:
	std::string fullName;
	long acctNum;
	double balance;
public:
	Brass(const std::string& s = "Nullbody", long an = -1, double bal = 0.0);
	virtual ~Brass();

	void Deposit(double amt);
	virtual void Withdraw(double amt);
	double Balance() const;
	virtual void ViewAcct() const;
	};

format setFormat();
void restore(format f, precis p);


#endif


