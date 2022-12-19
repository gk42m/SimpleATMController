#include "CashBin.h"

CashBin::CashBin(const int64_t balance) : balance_(balance) {
}

bool CashBin::CanDeposit(int64_t cash) const noexcept {
	return true;
}
bool CashBin::CanWithdraw(int64_t cash) const noexcept {
	return balance_ >= cash;
}

int64_t CashBin::Deposit(int64_t cash) noexcept {
	balance_ += cash;
	return balance_;
}

int64_t CashBin::Withdraw(int64_t cash) noexcept {
	balance_ -= cash;
	return balance_;
}
