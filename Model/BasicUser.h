#pragma once
#ifndef GUARD_BasicUser
#define GUARD_BasicUser

#include "stdafx.h"
#include "Core.h"


//First derive class from the Core
class BasicUser:public Core
{
public:

//Default constructor
	BasicUser();

//Rule of three copy/assigned/destructor
	BasicUser(const BasicUser&);
	BasicUser& operator=(const BasicUser&);
	~BasicUser();

//Function to get or set the balance
	 void setBalance(unsigned int b) { balance = b; }
	 unsigned int getBalance() const { return balance; }

//Function to get and set the economy account
	std::vector<unsigned int> getEconomy_account() { return economy_accounts; }
	void setEconomy_account(std::vector<unsigned int > e) { economy_accounts = e; }

////Functions without acces for the Basic User
	 void setName(std::string n) { name = n; }
	 void setAccountNumber(int accountNumber) { account_number = accountNumber; }
//Public function for accesing data
	 std::string getName() const { return name; }
     int getAccountNumber() const { return account_number; }

//Extend the economy_account vector
	virtual void extend_economy_account(unsigned int&);

//Convert BasicUser info to string
	 std::string to_String();

protected:

//Data to store money and number of economy account
	unsigned int balance;
	std::vector<unsigned int> economy_accounts;
};

//Outside the class function
bool check_economy_account_number(unsigned int);


#endif
