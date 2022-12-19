#pragma once
#include "ICashBin.h"

class CashBin : public ICashBin
{
public:
	CashBin(const int64_t balance);
	bool CanDeposit(int64_t cash) const noexcept override;
	bool CanWithdraw(int64_t cash) const noexcept override;
	int64_t Deposit(int64_t cash) noexcept override;
	int64_t Withdraw(int64_t cash) noexcept override;

private:
	int64_t balance_ = 0;
};

