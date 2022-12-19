#pragma once
#include "define.h"

class IAuthenticationDevice {
public:
	virtual std::string GetPinNumber() const = 0;
};

class IAuthenticationDeviceReader {
public:
	virtual std::string Read() = 0;
	virtual void Insert(std::weak_ptr<IAuthenticationDevice> device) = 0;
	virtual void Exit() = 0;
};