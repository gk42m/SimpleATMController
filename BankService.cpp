#include "BankService.h"

MockBank::MockBank(const std::map<std::string, BankAccounts>& bankAccounts) : bankAccounts_(bankAccounts) {
}

bool MockBank::CheckValidation(const std::string& pinNumber) {
	//actually call REST API
	return pinNumber.starts_with("PinNumber");
}

BankAccounts MockBank::GetAccounts(const std::string& pinNumber) {
	//actually call REST API
	return bankAccounts_[pinNumber];
}

bool MockBank::CanDeposit(const std::string& pinNumber, const std::string& accountId, int64_t cash) {
	return true;
}

bool MockBank::CanWithdraw(const std::string& pinNumber, const std::string& accountId, int64_t cash) {
	auto& account = bankAccounts_[pinNumber][accountId];
	return account.balance >= cash;
}

int64_t MockBank::Deposit(const std::string& pinNumber, const std::string& accountId, int64_t cash) {
	auto& account = bankAccounts_[pinNumber][accountId];
	account.balance += cash;
	return account.balance;
}

int64_t MockBank::Withdraw(const std::string& pinNumber, const std::string& accountId, int64_t cash) {
	auto& account = bankAccounts_[pinNumber][accountId];
	account.balance -= cash;
	return account.balance;
}