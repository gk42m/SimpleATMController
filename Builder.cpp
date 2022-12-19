#include "builder.h"
#include "AuthenticationDevice.h"
#include "BankService.h"
#include "CashBin.h"

std::shared_ptr<ATMController> Builder::BuildATMController() {
	auto controller = std::make_shared<ATMController>(std::make_unique<CheckCardReader>(),
		std::make_unique<CashBin>(100000),
		std::make_unique<MockBank>(std::map<std::string, BankAccounts>({
			{
				PinNumber, {
					{"1", {"1", 10000}},
					{"2", {"2", 20000}},
					{"3", {"3", 30000}}
				}
			}
			})));
	return controller;
}