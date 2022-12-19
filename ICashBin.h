#pragma once

#include "define.h"

class ICashBin {
public:
	virtual bool CanDeposit(int64_t cash) const noexcept = 0;
	virtual bool CanWithdraw(int64_t cash) const noexcept = 0;
	virtual int64_t Deposit(int64_t cash) noexcept = 0;
	virtual int64_t Withdraw(int64_t cash) noexcept = 0;
};
