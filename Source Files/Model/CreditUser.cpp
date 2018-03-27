#include "stdafx.h"
#include "CreditUser.h"
#include <stdexcept>

using namespace std;


CreditUser::CreditUser() { 
	credit = formula_maximum_credit_allowed(salary);
}
CreditUser::~CreditUser() {
	balance = 0;
	salary = 0;
	credit = 0;
	economy_accounts.clear();
	economy_accounts.shrink_to_fit();
}

//Convert CreditUser info to string
string CreditUser::to_String() {
	string tempo_economy_account;
	if (check_economy_account_number(economy_accounts.size())) {
		for (auto&& i : economy_accounts)
			tempo_economy_account += to_string(i) + " ";
	}
	return (" " + Core::to_String() + " " + std::to_string(balance) + " " + std::to_string(salary) + " " + std::to_string(credit) + " " + tempo_economy_account);
}

void CreditUser::calculate_max_credit() {
	credit = formula_maximum_credit_allowed(salary);
}

//Functions outsiede the class 
int formula_maximum_credit_allowed(unsigned int& s) {
	if (s <= 1500)
		return (int)(s * 1.5);
	else if (s > 1500 || s <= 2500)
		return (int)(s * 2);
	else if (s > 2500 || s < 4000)
		return (int)(s * 2.2);
	else 
		return (int)(s * 2.3);

}