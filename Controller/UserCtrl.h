#pragma once
#ifndef GUARD_UserCtrl
#define GUARD_UserCtrl

#include "stdafx.h"
#include "UserRepo.h"


class UserCtrl
{
public:
//Maximum accounts that an user can create and stor money in them
	const static int maximum_economy_accounts = 2;
	const static int maximum_economy_accounts_gold = 3;

//Default constructor
	UserCtrl();
	virtual ~UserCtrl();

//Function that all Users and Employee have acces
	virtual void add_economy_account(int&);
	virtual void delete_economy_account(int&);
	virtual void transfer_money(int&, int&, unsigned int&);
	virtual void withdrow_money(int&, unsigned int&);
	virtual void deoposit_money(int&, unsigned int&);
	virtual void getbalance(int&);
	virtual void transfer_money_to_economy_account(int&, int&, unsigned int&);
	virtual void transfer_money_from_economy_account(int&, int&, unsigned int&);

//Function that Credit/Gold Users and Emplyee have acces
	virtual void deposit_creit(int&,  int&);
	virtual void withdrow_credit(int&,  int&);

//Functions with access for all employee
	void add_User(Core* );
	void delete_User(int&);
	void edit_User(int& , std::string& , int& );
	std::string show_user(int& );
	std::vector<Core*> get_all_users() const;

	std::vector<Core*>::iterator find_type_element(int&);
	bool is_valid(int&);

//Store and save the date
	void store_data() { user_repository.store_the_data(Users); }

protected:
	std::vector<Core *> Users;
private:
	UserRepo user_repository;
};

bool check_money(const unsigned int&);
bool check_economy_account_number(int& , std::vector<unsigned int> );
#endif
