#pragma once
#include "define.h"
#include "BankAccount.h"

class IBankService {
public:
	virtual bool CheckValidation(const std::string& pinNumber) = 0;
	virtual BankAccounts GetAccounts(const std::string& pinNumber) = 0;
	virtual bool CanDeposit(const std::string& pinNumber, const std::string& accountId, int64_t cash) = 0;
	virtual bool CanWithdraw(const std::string& pinNumber, const std::string& accountId, int64_t cash) = 0;
	virtual int64_t Deposit(const std::string& pinNumber, const std::string& accountId, int64_t cash) = 0;
	virtual int64_t Withdraw(const std::string& pinNumber, const std::string& accountId, int64_t cash) = 0;
};
