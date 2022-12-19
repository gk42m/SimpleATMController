#pragma once
#include "define.h"
#include "IAuthenticationDevice.h"

class CheckCard : public IAuthenticationDevice {
public:
	CheckCard(const std::string& pinNumber);
	std::string GetPinNumber() const override;

private:
	std::string pinNumber_ = {};
};


class CheckCardReader : public IAuthenticationDeviceReader {
public:
	std::string Read() override;
	void Exit() override;
	void Insert(std::weak_ptr<IAuthenticationDevice> inputDevice) override;

private:
	std::weak_ptr<IAuthenticationDevice> inputDevice_ = {};
};