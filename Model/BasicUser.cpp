#include "stdafx.h"
#include "BasicUser.h"
#include <stdexcept>

using namespace std;

//Function from Basic User class
//Default constructor
BasicUser::BasicUser() :balance(0) { }

//Rule of three copy/assigned/destructor
BasicUser::BasicUser(const BasicUser& user) {
	this->account_number = user.account_number;
	this->name = user.name;
	this->balance = user.balance;

	if (check_economy_account_number(user.economy_accounts.size())) {
		for (auto&& i : user.economy_accounts)
			this->economy_accounts.push_back(i);
	}
}
BasicUser& BasicUser::operator=(const BasicUser& user) {
	if (this != &user) {
		this->balance = 0;
		this->economy_accounts.clear();
		this->economy_accounts.shrink_to_fit();

		if (check_economy_account_number(user.economy_accounts.size())) {
			for (auto&& i : user.economy_accounts)
				this->economy_accounts.push_back(i);
		}
	}
	return *this;
}
BasicUser::~BasicUser() {
	balance = 0;
	economy_accounts.clear();
	economy_accounts.shrink_to_fit();
}


//Extend the economy_account vector
void BasicUser::extend_economy_account(unsigned int& money) {
	if (economy_accounts.size() <= 2)
		economy_accounts.push_back(money);
	else
		throw domain_error("You've reached your limit of economy accounts!");
}

//Convert BasicUser info to string
string BasicUser::to_String() {
	string tempo_economy_account;
	if (check_economy_account_number(economy_accounts.size())) {
		for (auto&& i : economy_accounts)
			tempo_economy_account += to_string(i) + " ";
	}
	return (" " + Core::to_String() + " " + std::to_string(balance) + " " + tempo_economy_account);
}

//Outside the class functions
bool check_economy_account_number(unsigned int economy_account_number) {
	if (economy_account_number <= 2)
		return true;
	else {
		throw domain_error("This account dosent have any open economy account !");
		return false;
	}
}

