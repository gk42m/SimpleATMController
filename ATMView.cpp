#include "ATMView.h"
#include <iostream>
#include <iomanip>
#include <format>

ATMView::ATMView(const std::shared_ptr<IATMController>& controller) {
	controller_ = controller;
	controller_->SetAuthenticationCompletedHandler([this](bool success) {

		std::cout << std::format("Card Inserted.") << std::endl;
		std::cout << std::format("Authentication {}", success ? "Completed." : "Failed.") << std::endl << std::endl;
		std::cout << std::format("------------------------") << std::endl;
		std::cout << std::format("Account List") << std::endl;
		std::cout << std::format("------------------------") << std::endl;

		std::cout << "* AccountId | Balance" << std::endl;
		auto accounts = controller_->GetAccounts();
		for (const auto& [k, v] : accounts) {
			std::cout << "> " << k << std::setw(11) << " : " << v.balance << std::endl;
		}
		std::cout << std::endl;

		std::cout << "Select Account. Enter AccountId correctly : ";
		std::string accountId;
		std::cin >> accountId;
		std::cout << std::endl;

		std::cout << std::format("------------------------") << std::endl;
		if (auto it = accounts.find(accountId); it != accounts.end()) {
			std::cout << std::format("Account Id : {}, Balance : {}", it->second.id, it->second.balance) << std::endl;

			std::cout << std::format("------------------------") << std::endl;
			std::cout << "1. Deposit" << std::endl;
			std::cout << "2. Withdraw" << std::endl;
			std::cout << "What do you want : ";

			std::string isDeposit;
			std::cin >> isDeposit;
			std::cout << std::endl;

			std::cout << "How much : ";
			int64_t cash = 0;
			std::cin >> cash;
			std::cout << std::endl;

			if (isDeposit == "1") {
				const auto balance = controller_->Deposit(it->second.id, cash);
				if (balance == -1) {
					std::cout << "Deposit Failed!" << std::endl;
				}
				else {
					std::cout << "Deposit Success!" << std::endl;
					std::cout << std::format("Account Id : {}, Balance : {}", it->second.id, balance) << std::endl;
				}
			}
			else {
				const auto balance = controller_->Withdraw(it->second.id, cash);
				if (balance == -1) {
					std::cout << "Withdraw Failed!" << std::endl;
				}
				else {
					std::cout << "Withdraw Success!" << std::endl;
					std::cout << std::format("Account Id : {}, Balance : {}", it->second.id, balance) << std::endl;
				}
			}

			controller_->Exit();
		}
	});
}
