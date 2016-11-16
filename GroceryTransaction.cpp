#include "GroceryTransaction.h"
#include <string>
GroceryTransaction::GroceryTransaction(){
}
GroceryTransaction::GroceryTransaction(std::string store_name, std::string transaction_date,
	int transaction_id,
	double transaction_amount)
		: Transaction(transaction_date, transaction_id, transaction_amount),
		store_name_(store_name) {
}
GroceryTransaction::~GroceryTransaction(){
	std::cout << "\nDeleting Grocery Store Transaction\n";
}
const std::string GroceryTransaction::get_store_name() {
	return store_name_;
}
void GroceryTransaction::set_store_name(std::string store_name) {
	store_name_ = store_name;
}
double GroceryTransaction::earn_points() {
	return 2.5*this->transaction_amount_;
}
void GroceryTransaction::display() {
	std::cout << transaction_date_ << "\tGrocery\t\t\t" << store_name_ << "\t\t\t$" << transaction_amount_ << std::endl;
}