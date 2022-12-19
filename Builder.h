#pragma once
#include "define.h"
#include "ATMController.h"

constexpr auto PinNumber = "PinNumber-1234-5678-2345";

class Builder
{
public:
	static std::shared_ptr<ATMController> BuildATMController();
};

