#include <iostream>
#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction{
public:
	Transaction();
	Transaction(std::string, int, double);
	virtual ~Transaction();
	bool const operator==(const Transaction&);
	virtual void display() = 0;
	virtual double earn_points() = 0;
	std::string get_transaction_date();
	int get_transaction_id();
	double get_transaction_amount();
	void set_transaction_date(std::string);
	void set_transaction_id(int);
	void set_transaction_amount(double);
protected:
	std::string transaction_date_;
	int transaction_id_;
	double transaction_amount_ = 0.0;
};

#endif