#ifndef DEPARTMENTSTORESTRANSACTION_H
#define DEPARTMENTSTORESTRANSACTION_H

#include "transaction.h"
class DepartmentStoreTransaction :
	public Transaction
{
public:
	DepartmentStoreTransaction();
	DepartmentStoreTransaction(std::string, int, std::string, int, double);
	~DepartmentStoreTransaction();
	const std::string get_department_name();
	const int get_return_policy();
	void set_department_name(std::string);
	void set_return_policy(int);
	double earn_points();
	void display();
private:
	std::string department_name_;
	int return_policy_;
};

#endif