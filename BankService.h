#pragma once
#include "IBankService.h"

class MockBank : public IBankService {
public:
	MockBank(const std::map<std::string, BankAccounts>& bankAccounts);
	bool CheckValidation(const std::string& pinNumber) override;
	BankAccounts GetAccounts(const std::string& pinNumber) override;
	bool CanDeposit(const std::string& pinNumber, const std::string& accountId, int64_t cash) override;
	bool CanWithdraw(const std::string& pinNumber, const std::string& accountId, int64_t cash) override;
	int64_t Deposit(const std::string& pinNumber, const std::string& accountId, int64_t cash) override;
	int64_t Withdraw(const std::string& pinNumber, const std::string& accountId, int64_t cash) override;

private:
	std::map<std::string, BankAccounts> bankAccounts_ = {};
};
