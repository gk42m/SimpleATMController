#pragma once
#include "define.h"
#include "IATMController.h"
#include "IBankService.h"
#include "ICashBin.h"

class ATMController : public IATMController {
public:
	ATMController(std::unique_ptr<IAuthenticationDeviceReader> deviceReader,
		std::unique_ptr<ICashBin> cashBin,
		std::unique_ptr<IBankService> bankService);
	void UserAction_InsertAuthenticationDevice(std::weak_ptr<IAuthenticationDevice> inputDevice);
	void SetAuthenticationCompletedHandler(const AuthenticationCompletedHandler& onAuthenticationCompleted) override;
	BankAccounts GetAccounts() override;
	int64_t Deposit(const std::string& accountId, int64_t cash) override;
	int64_t Withdraw(const std::string& accountId, int64_t cash) override;
	void Exit() override;

private:
	std::unique_ptr<IAuthenticationDeviceReader> deviceReader_ = {};
	std::unique_ptr<ICashBin> cashBin_ = {};
	std::unique_ptr<IBankService> bankService_ = {};
	AuthenticationCompletedHandler onAuthenticationCompleted_ = {};
};

