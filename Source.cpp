#include <iostream>
#include "Customer.h"

int main() {
	Customer* ptr_customer = new Customer("Sean Hulse", "4501-1234-1111-1453");
	ptr_customer->read_transactions("D:/workspace/CreditCard_Lab3/CreditCard_Lab3/example_file.txt");
	ptr_customer->report_all_transactions();
	ptr_customer->report_reward_summary();
	delete ptr_customer;

	//Testing Duplicate Transactions
	int i = 0;
	Customer* ptr_test_cust = new Customer("Test Test", "1111-1111-1111-1111");
	ptr_test_cust->read_transactions("D:/workspace/CreditCard_Lab3/CreditCard_Lab3/example_file.txt");
	for (int i = 0; i < 15; i++) {
		for (int j = i + 1; j < 16; j++) {
			if (*ptr_test_cust->get_ptr_transaction(i) == *ptr_test_cust->get_ptr_transaction(j)) {
				std::cout << "\n\nFound duplicate transaction where indices [" << i << "] and [" << j << "]\n";
			}
		}
	}

	getchar();
	return 0;
}