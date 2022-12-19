#pragma once
#include "define.h"

class BankAccount
{
public:
	std::string id = {};
	int64_t balance = {};
};

using BankAccounts = std::map<std::string, BankAccount>;

