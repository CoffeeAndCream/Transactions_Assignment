#include "DepartmentStoreTransaction.h"
#include <string>
DepartmentStoreTransaction::DepartmentStoreTransaction(){
}
DepartmentStoreTransaction::DepartmentStoreTransaction(
	std::string department_name, 
	int return_policy, 
	std::string transaction_date,
	int transaction_id,
	double transaction_amount) 
							: Transaction(transaction_date, transaction_id, transaction_amount),
							department_name_(department_name),
							return_policy_(return_policy){
}
DepartmentStoreTransaction::~DepartmentStoreTransaction(){
	std::cout << "\nDeleting Store Transaction\n";
}
const std::string DepartmentStoreTransaction::get_department_name() {
	return department_name_;
}
const int DepartmentStoreTransaction::get_return_policy() {
	return return_policy_;
}
void DepartmentStoreTransaction::set_department_name(std::string department_name) {
	department_name_ = department_name;
}
void DepartmentStoreTransaction::set_return_policy(int return_policy) {
	return_policy_ = return_policy;
}
double DepartmentStoreTransaction::earn_points() {
	return 1.5*this->transaction_amount_;
}
void DepartmentStoreTransaction::display() {
	std::cout << transaction_date_ << "\tDepartment Store\t" << department_name_ << ", return: " << return_policy_ << " days\t$" << transaction_amount_ << std::endl;
}