#ifndef BANKINGTRANSACTION_H
#define BANKINGTRANSACTION_H
#include "Transaction.h"

class BankingTransaction :
	public Transaction
{
public:
	BankingTransaction();
	BankingTransaction(std::string, double, std::string, int, double);
	virtual ~BankingTransaction();
	std::string get_banking_type();
	double get_fee_charge();
	void set_banking_type(std::string);
	void set_fee_charge(double);
	double earn_points();
	void display();
private:
	std::string banking_type_;
	double fee_charge_;
};

#endif