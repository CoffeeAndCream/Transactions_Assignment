#include "BankingTransaction.h"
#include <string>

BankingTransaction::BankingTransaction(){
}
BankingTransaction::BankingTransaction(
	std::string banking_type,
	double fee_charge,
	std::string transaction_date,
	int transaction_id,
	double transaction_amount)
		: Transaction(transaction_date, transaction_id, transaction_amount),
		banking_type_(banking_type),
		fee_charge_(fee_charge) {

}
BankingTransaction::~BankingTransaction(){
	std::cout << "\nDeleting Banking Transaction\n";
}
std::string BankingTransaction::get_banking_type() {
	return banking_type_;
}
double BankingTransaction::get_fee_charge() {
	return fee_charge_;
}
void BankingTransaction::set_banking_type(std::string banking_type) {
	banking_type_ = banking_type;
}
void BankingTransaction::set_fee_charge(double fee_charge) {
	fee_charge_ = fee_charge;
}
double BankingTransaction::earn_points(){
	return 0;
}
void BankingTransaction::display() {
	std::cout << transaction_date_ << "\tBanking\t\t\t" << banking_type_ << "\t\t\t$" << transaction_amount_ << std::endl;
}