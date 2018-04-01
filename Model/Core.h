// The core class(interface) for our users
// This class will be core for the next classes : LowEmp, HighEmp, Adiministrator,
//													BasicUser, CreditUser, GoldUser

#pragma once
#ifndef GUARD_Core
#define GUARD_Core

#include "stdafx.h"
#include <string>
#include <vector>

//Core Class
class Core
{
public:

//default constructors/deconstructor
	Core();
	virtual ~Core();

//Public function for accesing data
//Pure virtual functions
	virtual void setName(std::string n) = 0;
	virtual void setAccountNumber(int accountNumber) = 0;
	virtual std::string getName() const = 0;
	virtual	int getAccountNumber() const = 0;

//Function to convert all variable in strings
	virtual std::string to_String();

protected:

//Mandatory data for every user
	int account_number;
	std::string name;

//Acces type for employee
	std::string access = "No Access!";
};

#endif
