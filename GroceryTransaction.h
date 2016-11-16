#ifndef GROCERYTRANSACTION_H
#define GROCERYTRANSACTION_H

#include "Transaction.h"
class GroceryTransaction :
	public Transaction
{
public:
	GroceryTransaction();
	GroceryTransaction(std::string, std::string, int, double);
	~GroceryTransaction();
	const std::string get_store_name();
	void set_store_name(std::string);
	double earn_points();
	void display();
private:
	std::string store_name_;
};

#endif