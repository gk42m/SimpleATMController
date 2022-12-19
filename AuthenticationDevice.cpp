#include "AuthenticationDevice.h"

CheckCard::CheckCard(const std::string& pinNumber) : pinNumber_(pinNumber) {
}

std::string CheckCard::GetPinNumber() const {
	return pinNumber_;
}

std::string CheckCardReader::Read() {
	//mock read action;
	return inputDevice_.expired() ? "" : inputDevice_.lock()->GetPinNumber();
}
void CheckCardReader::Exit() {
	inputDevice_.reset();
}
void CheckCardReader::Insert(std::weak_ptr<IAuthenticationDevice> inputDevice) {
	inputDevice_ = inputDevice;
}