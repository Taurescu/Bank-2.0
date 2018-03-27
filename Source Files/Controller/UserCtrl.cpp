#include "stdafx.h"
#include "UserCtrl.h"
#include <iostream>


using namespace std;

//default construcotr
UserCtrl::UserCtrl() {
	user_repository.read_all_users(Users);
}
UserCtrl::~UserCtrl() {}


//Function that find the element based on account_number
vector<Core*>::iterator UserCtrl::find_type_element(int& account_number) {
	vector<Core*>::iterator it = Users.begin();
	for (it; it != Users.end(); ++it) {
		if ((*it)->getAccountNumber() == account_number)
			return it;
	}
	return it;
}

bool UserCtrl::is_valid(int& account_number) {
	vector<Core*>::iterator it = find_type_element(account_number);
	if (it != Users.end())
		return true;
	else
		return false;
}


//Function that  all Users and  all Employee have acces
void UserCtrl::add_economy_account(int& account_number) {
	vector<Core*>::iterator it = find_type_element(account_number);
	if (it != Users.end()) {
		BasicUser* gold_user = dynamic_cast<BasicUser*>(*it);
		if (gold_user->getAccountNumber() >= 100000 && gold_user->getAccountNumber() <= 50000001) {
			if (gold_user->getEconomy_account().size() < maximum_economy_accounts) {
				vector<unsigned int> temp_economy = gold_user->getEconomy_account();
				temp_economy.push_back(0);
				gold_user->setEconomy_account(temp_economy);
			}
			else
				throw domain_error("You have reached maximum account number alowed for your type of account");
		}
		else if (gold_user->getAccountNumber() >= 10000 && gold_user->getAccountNumber() <= 99999) {
			if (gold_user->getEconomy_account().size() < maximum_economy_accounts_gold) {
				vector<unsigned int> temp_economy = gold_user->getEconomy_account();
				temp_economy.push_back(0);
				gold_user->setEconomy_account(temp_economy);
			}
			else
				throw domain_error("You have reached maximum account number alowed for your type of account");
		}
	}
	else
		throw domain_error("Invalid account number");
}
void UserCtrl::delete_economy_account(int& account_number) {
	vector<Core*>::iterator it = find_type_element(account_number);
	if (it != Users.end()) {
		BasicUser* basic_user = dynamic_cast<BasicUser*>(*it);
		if (basic_user->getEconomy_account().size() != 0) {
			vector<unsigned int> temp_economy = basic_user->getEconomy_account();
			temp_economy.erase(temp_economy.end()- 1);
			basic_user->setEconomy_account(temp_economy);
		}
	}
	else
		throw domain_error("Invalid account number");
}
void UserCtrl::transfer_money(int& sender_account_number, int& reciver_account_number, unsigned int& money) {
	check_money(money);
	vector<Core*>::iterator it_sender = find_type_element(sender_account_number);
	vector<Core*>::iterator it_reciver = find_type_element(reciver_account_number);
	if (it_sender != Users.end() && it_reciver != Users.end()) {
		BasicUser* sender_user = dynamic_cast<BasicUser*>(*it_sender);
		BasicUser* reciver_user = dynamic_cast<BasicUser*>(*it_reciver);
 		if (sender_user->getBalance() >= money) {
			sender_user->setBalance(sender_user->getBalance() - money);
			reciver_user->setBalance(reciver_user->getBalance() + money);
		}
		else 
			throw domain_error("Insufficient funds");
	}
	else
		throw domain_error("Invalid account number");
}
void UserCtrl::withdrow_money(int& account_number, unsigned int& money) {

	check_money(money);
	vector<Core*>::iterator it = find_type_element(account_number);
	if (it != Users.end()) {
		BasicUser* basic_user = dynamic_cast<BasicUser*>(*it);
		if (basic_user->getBalance() > money)
			basic_user->setBalance(basic_user->getBalance() - money);
		else
			throw domain_error("Insufficient funds");
	}
	else
		throw domain_error("Invalid account number");
}
void UserCtrl::deoposit_money(int& account_number, unsigned int& money) {

	check_money(money);
	vector<Core*>::iterator it = find_type_element(account_number);
	if (it != Users.end()) {
		BasicUser* basic_user = dynamic_cast<BasicUser*>(*it);
		basic_user->setBalance(basic_user->getBalance() + money);
	}
	else
		throw domain_error("Invalid account number");
}
void UserCtrl::transfer_money_to_economy_account(int& account_number, int& economy_account_number, unsigned int& money) {

	check_money(money);
	vector<Core*>::iterator it = find_type_element(account_number);
	if (it != Users.end()) {
		BasicUser* basic_user = dynamic_cast<BasicUser*>(*it);
		if (check_economy_account_number(economy_account_number, basic_user->getEconomy_account())) {
			vector<unsigned int> temp = basic_user->getEconomy_account();
			temp[economy_account_number - 1] += money;
			basic_user->setEconomy_account(temp);
			basic_user->setBalance(basic_user->getBalance() - money);
		}
	}
	else
		throw domain_error("Invalid account number");
}
void UserCtrl::transfer_money_from_economy_account(int& account_number, int& economy_account_number, unsigned int& money) {
	
	check_money(money);
	vector<Core*>::iterator it = find_type_element(account_number);
	if (it != Users.end()) {
		BasicUser* basic_user = dynamic_cast<BasicUser*>(*it);
		if (check_economy_account_number(economy_account_number, basic_user->getEconomy_account())) {
			vector<unsigned int> temp = basic_user->getEconomy_account();
			if (temp[economy_account_number] >= money) {
				temp[economy_account_number] -= money;
				basic_user->setEconomy_account(temp);
				basic_user->setBalance(basic_user->getBalance() + money);
			}
			else
				throw domain_error("Insufficient funds");
		}
	}
	else
		throw domain_error("Invalid account number");
}


//Function that Credit/Gold Users and Emplyee have acces
void UserCtrl::deposit_creit(int& account_number,  int& money) {

	check_money(money);
	vector<Core*>::iterator it = find_type_element(account_number);
	if (it != Users.end()) {
		CreditUser* credit_user = dynamic_cast<CreditUser*>(*it);
		credit_user->setCredit(credit_user->getCredit() + money);
	}
	else
		throw domain_error("Invalid account number");
}
void UserCtrl::withdrow_credit(int& account_number,  int& money) {

	check_money(money);

	vector<Core*>::iterator it = find_type_element(account_number);
	if (it != Users.end()) {
		CreditUser* credit_user = dynamic_cast<CreditUser*>(*it);
		if(credit_user->getCredit() >= money )
			credit_user->setCredit(credit_user->getCredit() - money);
		else 
			throw domain_error("Insufficient funds");
	}
	else
		throw domain_error("Invalid account number");
}
void UserCtrl::getbalance(int& account_number) {
	vector<Core*>::iterator it = find_type_element(account_number);
	if (it != Users.end()) {
		BasicUser* basic_user = dynamic_cast<BasicUser*>(*it);
		cout << basic_user->getBalance() << endl;
		system("PAUSE");
		
	}
	else
		throw domain_error("Invalid account number");
}

//Functions with access for all employee
void UserCtrl::add_User(Core* user_type)
{
	user_repository.add_user(user_type);
	user_repository.populate_pointer_vector(Users);


}
void UserCtrl::delete_User(int& account_number) {
	vector<Core*>::iterator it = UserCtrl::find_type_element(account_number);
	if (it != Users.end()) {
		Users.erase(it);
	}
	else
		throw domain_error("Invalid account number");
}
void UserCtrl::edit_User(int& account_number, string& name, int& salary) {
	vector<Core*>::iterator it = find_type_element(account_number);
	if (it != Users.end()) {
		CreditUser* credit_user = dynamic_cast<CreditUser*>(*it);
		if (credit_user) {
			credit_user->setSalary(salary);
			credit_user->setName(name);
		}
		else {
			BasicUser* basic_user = dynamic_cast<BasicUser*>(*it);
			if (basic_user)
				basic_user->setName(name);
		}
	}
	else
		throw domain_error("Invalid account number");
}
string UserCtrl::show_user(int& account_number) {
	vector<Core*>::iterator it = find_type_element(account_number);
	BasicUser* basic_user = dynamic_cast<BasicUser*>(*it);
	return basic_user->to_String();
}
vector<Core*> UserCtrl::get_all_users() const { return Users; }


//Outside the class functions

bool check_money(const unsigned int& money) {
	if (money < 0) {
		throw domain_error("You've enterd a wrong number!");
		return false;
	}
	else
		return true;
}
bool check_economy_account_number(int& economy_account_number, vector<unsigned int> economy_account) {
	if (economy_account_number <= 3 && economy_account.size() >= economy_account_number)
		return true;
	else {
		throw domain_error("This account dosent have any open economy account !");
		return false;
	}
}
