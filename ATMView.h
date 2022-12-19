#pragma once

#include "define.h"
#include "IATMController.h"

class ATMView
{
public:
	ATMView(const std::shared_ptr<IATMController>& controller);

private:
	std::shared_ptr<IATMController> controller_ = {};
};

