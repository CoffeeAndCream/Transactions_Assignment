#include "Transaction.h"
#include <string>
Transaction::Transaction(){
}
Transaction::Transaction(
	std::string transaction_date_,
	int transaction_id_,
	double transaction_amount_) :
		transaction_date_(transaction_date_),
		transaction_id_(transaction_id_),
		transaction_amount_(transaction_amount_) {

}
Transaction::~Transaction(){
	std::cout << "Transaction " << transaction_id_ << " destroyed.\n";
}
bool const Transaction::operator==(const Transaction& transaction_rh) {
	return (this->transaction_date_ == transaction_rh.transaction_date_) && (this->transaction_id_ == transaction_rh.transaction_id_);
}
void Transaction::display() { }
double Transaction::earn_points() { return 0; }
std::string Transaction::get_transaction_date() {
	return transaction_date_;
}
int Transaction::get_transaction_id() {
	return transaction_id_;
}
double Transaction::get_transaction_amount() {
	return transaction_amount_;
}
void Transaction::set_transaction_date(std::string transaction_date) {
	transaction_date_ = transaction_date;
}
void Transaction::set_transaction_id(int transaction_id) {
	transaction_id_ = transaction_id;
}
void Transaction::set_transaction_amount(double transaction_amount) {
	transaction_amount_ = transaction_amount;
}