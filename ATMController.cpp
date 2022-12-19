#include "ATMController.h"

ATMController::ATMController(std::unique_ptr<IAuthenticationDeviceReader> deviceReader,
	std::unique_ptr<ICashBin> cashBin,
	std::unique_ptr<IBankService> bankService) :
	deviceReader_(std::move(deviceReader)), cashBin_(std::move(cashBin)), bankService_(std::move(bankService)) {
}

void ATMController::UserAction_InsertAuthenticationDevice(std::weak_ptr<IAuthenticationDevice> inputDevice) {
	//mock action. pretend to be async process
	//1. User insert card
	//2. deviceReader read pinNumber
	//3. authenticator request validation check to BankService
	//4. response callback to caller thread

	deviceReader_->Insert(inputDevice);

	auto result = bankService_->CheckValidation(deviceReader_->Read());

	if (onAuthenticationCompleted_) {
		onAuthenticationCompleted_(result);
	}
}

void ATMController::SetAuthenticationCompletedHandler(const AuthenticationCompletedHandler& onAuthenticationCompleted) {
	onAuthenticationCompleted_ = onAuthenticationCompleted;
}

BankAccounts ATMController::GetAccounts() {
	return bankService_->GetAccounts(deviceReader_->Read());
}

int64_t ATMController::Deposit(const std::string& accountId, int64_t cash) {
	if (!cashBin_->CanDeposit(cash) || !bankService_->CanDeposit(deviceReader_->Read(), accountId, cash)) {
		return -1;
	}
	cashBin_->Deposit(cash);
	return bankService_->Deposit(deviceReader_->Read(), accountId, cash);
}

int64_t ATMController::Withdraw(const std::string& accountId, int64_t cash) {
	if (!cashBin_->CanWithdraw(cash) || !bankService_->CanWithdraw(deviceReader_->Read(), accountId, cash)) {
		return -1;
	}
	cashBin_->Withdraw(cash);
	return bankService_->Withdraw(deviceReader_->Read(), accountId, cash);
}
void ATMController::Exit() {
	deviceReader_->Exit();
}