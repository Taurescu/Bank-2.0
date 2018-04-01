#pragma once
#ifndef GUARD_CreditUser
#define GUARD_CreditUser

#include "stdafx.h"
#include "BasicUser.h"


class CreditUser:public BasicUser
{
public:
//Default constructor/destructor
	CreditUser();
	virtual ~CreditUser();


//Functions to get and set the salary and credit;
	void setSalary(unsigned int s) { salary = s; }
	void setCredit(int c) { credit = c; }

	unsigned int getSalary() const { return salary; }
	int getCredit() const { return credit; }

//Convert CreditUser info to string
	 std::string to_String();

//Calculate the credit based on the salary
	virtual void calculate_max_credit();

protected:
	unsigned int salary;
	int credit;
};
int formula_maximum_credit_allowed(unsigned int&);
#endif
