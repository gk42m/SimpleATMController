#pragma once
#include "IAuthenticationDevice.h"
#include "BankAccount.h"

using AuthenticationCompletedHandler = std::function<void(bool)>;

class IATMController
{
public:
	virtual void SetAuthenticationCompletedHandler(const AuthenticationCompletedHandler& onAuthenticationCompleted) = 0;
	virtual BankAccounts GetAccounts() = 0;
	virtual int64_t Deposit(const std::string& accountId, int64_t cash) = 0;
	virtual int64_t Withdraw(const std::string& accountId, int64_t cash) = 0;
	virtual void Exit() = 0;
};

