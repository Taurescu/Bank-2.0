#pragma once
#ifndef GUARD_LowEmp
#define GUARD_LowEmp
#include "stdafx.h"
#include "Core.h"

class LowEmp:public Core
{
public:
	LowEmp();
	~LowEmp();

	//Public function for accesing data
	 void setName(std::string n) { name = n; }
	 void setAccountNumber(int accountNumber) { account_number = accountNumber; }

	 std::string getName() const { return name; }
	 int getAccountNumber() const { return account_number; }

//Function to convert all variable in strings
	 std::string to_String();

private:
	std::string access = "Low Access!";
};

#endif