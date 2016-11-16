#include <iostream>
#include "Transaction.h"
#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {
public:
	Customer();
	Customer(std::string, std::string);
	~Customer();
	void read_transactions(std::string);
	void report_all_transactions();
	void report_reward_summary();
	Transaction* get_ptr_transaction(int);
private:
	std::string customer_name_;
	std::string credit_card_number_;
	double transaction_balance_;
	double reward_points_ = 1000.0;
	Transaction* ptr_transaction_[32] = { NULL };
};

#endif 
