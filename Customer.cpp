#include "Customer.h"
#include "DepartmentStoreTransaction.h"
#include "BankingTransaction.h"
#include "GroceryTransaction.h"
#include <fstream>
#include <string>

Customer::Customer() {
}

Customer::Customer(std::string customer_name_,
				   std::string credit_card_number_)	:
						customer_name_(customer_name_),
						credit_card_number_(credit_card_number_),
						transaction_balance_(0),
						reward_points_(1000){
}

Customer::~Customer(){
	int i = 0;
	while(ptr_transaction_[i]){
		delete ptr_transaction_[i];
		i++;
	}
}

void Customer::read_transactions(std::string path) {
	char transaction_type;
	int transaction_counter = 0;
	DepartmentStoreTransaction* ptr_dept;
	BankingTransaction* ptr_bank;
	GroceryTransaction* ptr_grocery;
	std::ifstream is(path, std::ios::in);
	std::string date, id, balance, name, return_policy, fee_charge, type;
	if (!is) {
		std::cerr << "Error: Failed to open file\n";
		exit(-1);
	}
	else {
		while (!is.eof()) {
			is >> transaction_type;
			switch (transaction_type) {
			case 'D':
				ptr_transaction_[transaction_counter] = new DepartmentStoreTransaction();
				
				std::getline(is, type, '~');
				std::getline(is, date, '~');
				std::getline(is, id, '~');
				std::getline(is, balance, '~');
				std::getline(is, name, '~');
				std::getline(is, return_policy, '\n');

				ptr_dept = dynamic_cast<DepartmentStoreTransaction*>(ptr_transaction_[transaction_counter]);
				ptr_dept->set_transaction_date(date);
				ptr_dept->set_transaction_id(std::stoi(id));
				ptr_dept->set_department_name(name);
				ptr_dept->set_transaction_amount(std::stod(balance));
				ptr_dept->set_return_policy(std::stoi(return_policy));
				++transaction_counter;
				break;
			case 'B':
				ptr_transaction_[transaction_counter] = new BankingTransaction();
				
				std::getline(is, type, '~');
				std::getline(is, date, '~');
				std::getline(is, id, '~');
				std::getline(is, balance, '~');
				std::getline(is, name, '~');
				std::getline(is, fee_charge, '\n');

				ptr_bank = dynamic_cast<BankingTransaction*>(ptr_transaction_[transaction_counter]);
				ptr_bank->set_transaction_date(date);
				ptr_bank->set_transaction_id(std::stoi(id));
				ptr_bank->set_transaction_amount(std::stod(balance));
				ptr_bank->set_banking_type(name);
				ptr_bank->set_fee_charge(std::stod(fee_charge));
				++transaction_counter;
				break;
			case 'G':
				ptr_transaction_[transaction_counter] = new GroceryTransaction();
				
				std::getline(is, type, '~');
				std::getline(is, date, '~');
				std::getline(is, id, '~');
				std::getline(is, balance, '~');
				std::getline(is, name, '\n');

				ptr_grocery = dynamic_cast<GroceryTransaction*>(ptr_transaction_[transaction_counter]);
				ptr_grocery->set_transaction_date(date);
				ptr_grocery->set_transaction_id(std::stoi(id));
				ptr_grocery->set_transaction_amount(std::stod(balance));
				ptr_grocery->set_store_name(name);
				++transaction_counter;	
				break;
			default:
				std::cout << "Unknown transaction type. Skipping transaction.\n";
				++transaction_counter;
				break;
			}
		}
	}
}

void Customer::report_all_transactions() {
	double bank_transaction_total = 0, 
		dept_transaction_total = 0, 
		grocery_transaction_total = 0, 
		total_fee_charge = 0;
	int bank_transaction_count = 0, 
		dept_transaction_count = 0, 
		grocery_transaction_count = 0;

	BankingTransaction* ptr_bank;
	DepartmentStoreTransaction* ptr_dept;
	GroceryTransaction* ptr_grocery;
	std::cout << "DATE\t\tTRANSACTION TYPE\tINFO\t\t\tAMOUNT\n";
	for (int i = 0; i < 16; i++) {
		if (ptr_transaction_[i]) {
			ptr_transaction_[i]->display();
			if (ptr_bank = dynamic_cast<BankingTransaction*>(ptr_transaction_[i])) {
				total_fee_charge += ptr_bank->get_fee_charge();
				bank_transaction_count += 1;
				bank_transaction_total += ptr_bank->get_transaction_amount();
			}
			if (ptr_dept = dynamic_cast<DepartmentStoreTransaction*>(ptr_transaction_[i])) {
				dept_transaction_count += 1;
				dept_transaction_total += ptr_dept->get_transaction_amount();
			}
			if (ptr_grocery = dynamic_cast<GroceryTransaction*>(ptr_transaction_[i])) {
				grocery_transaction_count += 1;
				grocery_transaction_total += ptr_grocery->get_transaction_amount();
			}
		}
	}
	std::cout << "......................................................................................" << std::endl;
	std::cout << "Total fee charge:\t$" << total_fee_charge << std::endl;
	std::cout << "Total balance:   \t$" << bank_transaction_total + grocery_transaction_total + dept_transaction_total +total_fee_charge << std::endl;
	std::cout << "\t\t\t\tTransaction Summary\n\n";
	std::cout << "\tTransaction Type\tTransaction Count\tTotal Purchase\n";
	std::cout << "\tDepartment Store\t\t" << dept_transaction_count << "\t\t    $" << dept_transaction_total << std::endl;
	std::cout << "\tBanking\t\t\t\t" << bank_transaction_count << "\t\t    $" << bank_transaction_total << std::endl;
	std::cout << "\tGrocery\t\t\t\t" << grocery_transaction_count << "\t\t    $" << grocery_transaction_total << std::endl << std::endl;
	std::cout << "......................................................................................" << std::endl;
	std::cout << "\t\t\t\t\t\t\t    $" << bank_transaction_total + grocery_transaction_total + dept_transaction_total << std::endl;
	std::cout << std::endl;
}

void Customer::report_reward_summary() {
	BankingTransaction* ptr_bank;
	DepartmentStoreTransaction* ptr_dept;
	GroceryTransaction* ptr_grocery;
	double dept_reward_points = 0;
	double grocery_reward_points = 0;
	for (int i = 0; i < 16; i++) {
		if (ptr_transaction_[i]) {
			ptr_transaction_[i]->display();
			if (ptr_bank = dynamic_cast<BankingTransaction*>(ptr_transaction_[i])) {
				ptr_bank->earn_points();
			}
			if (ptr_dept = dynamic_cast<DepartmentStoreTransaction*>(ptr_transaction_[i])) {
				dept_reward_points += ptr_dept->earn_points();
			}
			if (ptr_grocery = dynamic_cast<GroceryTransaction*>(ptr_transaction_[i])) {
				grocery_reward_points += ptr_grocery->earn_points();
			}
		}
	}
	std::cout << "\n\nRewards Summary for " << customer_name_ << " XXXX-XXXX-XXXX-" << credit_card_number_.substr(15, 19) << std::endl << std::endl;
	std::cout << "\t\tPrevious Points Balance\t\t\t" << reward_points_ << std::endl;
	std::cout << "\t\t+Department Store Purchases\t\t" << dept_reward_points << std::endl;
	std::cout << "\t\t+Grocery Purchases\t\t\t" << grocery_reward_points << std::endl;
	std::cout << "......................................................................................" << std::endl;
	std::cout << " = Total Points available for redemption \t\t" << reward_points_ + grocery_reward_points + dept_reward_points << std::endl;
}

Transaction* Customer::get_ptr_transaction(int index) {
	return ptr_transaction_[index];
}