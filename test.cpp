#ifdef _RUN_TESTS
#include <catch.hpp>
#include "AuthenticationDevice.h"
#include "Builder.h"

SCENARIO("The user want to check account balance/Deposit/Withdraw.", "[atm]") {

	GIVEN("The User has a check card. CashBin Exists. MockBank Exists.") {
		auto checkCard = std::make_shared<CheckCard>(PinNumber);
		auto controller = Builder::BuildATMController();
		bool calledFunction = false;
		controller->SetAuthenticationCompletedHandler([&calledFunction, &controller](bool success) {
			calledFunction = true;
			});
		WHEN("User Insert Valid CheckCard.") {

			controller->UserAction_InsertAuthenticationDevice(checkCard);

			THEN("Passed ValidationCheck. User can show Account list") {
				REQUIRE(calledFunction == true);
				REQUIRE(controller->GetAccounts().size() == 3);
			}

			controller->Exit();
		}
		WHEN("User Insert Valid CheckCard. User can show Account list And Select Account-1, and then see a Balance") {

			controller->UserAction_InsertAuthenticationDevice(checkCard);

			//Select Account
			auto balance = controller->GetAccounts()["1"].balance;

			THEN("Show Balance.") {
				REQUIRE(calledFunction == true);
				REQUIRE(balance == 10000);
			}

			controller->Exit();
		}
		WHEN("User Insert Valid CheckCard. User can show Account list And Select Account-1, and Deposit 50,000 dollars") {

			controller->UserAction_InsertAuthenticationDevice(checkCard);

			auto balance = controller->GetAccounts()["1"].balance;
			auto result = controller->Deposit("1", 50000);

			THEN("Deposit Success.") {
				REQUIRE(balance == 10000);
				REQUIRE(result == 60000);
			}

			controller->Exit();
		}
		WHEN("User Insert Valid CheckCard. User can show Account list And Select Account-1, and Withdraw 50,000 dollars") {

			controller->UserAction_InsertAuthenticationDevice(checkCard);

			auto balance = controller->GetAccounts()["1"].balance;
			auto result = controller->Withdraw("1", 50000);

			THEN("Withdraw Failed.") {
				REQUIRE(balance == 10000);
				REQUIRE(result == -1);
			}

			controller->Exit();
		}
		WHEN("User Insert Valid CheckCard. User can show Account list And Select Account-1, and Withdraw 5,000 dollars") {

			controller->UserAction_InsertAuthenticationDevice(checkCard);

			auto balance = controller->GetAccounts()["1"].balance;
			auto result = controller->Withdraw("1", 5000);

			THEN("Withdraw Success.") {
				REQUIRE(balance == 10000);
				REQUIRE(result == 5000);
			}

			controller->Exit();
		}
	}
}

#endif