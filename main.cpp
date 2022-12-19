#include <iostream>
#include <thread>
#include <chrono>
#include "AuthenticationDevice.h"
#include "ATMView.h"
#include "Builder.h"

#ifndef _RUN_TESTS
int main()
{
	auto checkCard = std::make_shared<CheckCard>(PinNumber);
	auto controller = Builder::BuildATMController();
	auto view = std::make_unique<ATMView>(controller);

	std::cout << "Put in your check card." << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	controller->UserAction_InsertAuthenticationDevice(checkCard);

	std::cout << "To exit, type the any text and press Enter key " << std::endl;
	std::string str;
	std::cin >> str;
	return 0;
}
#endif