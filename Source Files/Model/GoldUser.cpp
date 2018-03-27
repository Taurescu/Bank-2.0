#pragma once
#include "stdafx.h"
#include "GoldUser.h"

using namespace std;

//Default constuctors

GoldUser::GoldUser() {
	credit = formula_maximum_credit_allowed(salary);
}

//
//Rule of three copy/assigned/destructor
GoldUser::GoldUser(const GoldUser& user) {
	this->account_number = user.account_number;
	this->name = user.name;
	this->balance = user.balance;
	this->credit = user.credit;
	this->salary = user.salary;

	if (check_economy_account_numbers(user.economy_accounts.size())) {
		for (auto&& i : user.economy_accounts)
			this->economy_accounts.push_back(i);
	}
}
GoldUser& GoldUser::operator=(const GoldUser& user) {
	if (this != &user) {
		this->balance = 0;
		this->economy_accounts.clear();
		this->economy_accounts.shrink_to_fit();

		if (check_economy_account_numbers(user.economy_accounts.size())) {
			for (auto&& i : user.economy_accounts)
				this->economy_accounts.push_back(i);
		}
	}
	return *this;
}
GoldUser::~GoldUser() {
	balance = 0;
	salary = 0;
	credit = 0;
	economy_accounts.clear();
	economy_accounts.shrink_to_fit();
}


//Extend the economy_account vector
void GoldUser::extend_economy_account(unsigned int& money) {
	if (economy_accounts.size() <= 3)
		economy_accounts.push_back(money);
	else
		throw domain_error("You've reached your limit of economy accounts!");
}

//Convert GoldUser info to string
string GoldUser::to_String() {
	string tempo_economy_account;
	if (check_economy_account_numbers(economy_accounts.size())) {
		for (auto&& i : economy_accounts)
			tempo_economy_account += to_string(i) + " ";
	}
	return (" " + Core::to_String() + " " + std::to_string(balance) + " " + std::to_string(salary) + " " + std::to_string(credit) + " " + tempo_economy_account);
}


//Outside the class Function
bool check_economy_account_numbers(unsigned int economy_account_number) {
	if (economy_account_number <= 3)
		return true;
	else {
		throw domain_error("This account dosent have any open economy account !");
		return false;
	}
}