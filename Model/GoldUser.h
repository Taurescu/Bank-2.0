 #pragma once
#ifndef GUARD_GoldUser
#define GUARD_GoldUser

#include "stdafx.h"
#include "CreditUser.h"


class GoldUser:public CreditUser
{
public:
	GoldUser();
	~GoldUser();

	GoldUser(const GoldUser&);
	GoldUser& operator=(const GoldUser&);

//Function to extend the economy class 
	 void extend_economy_account(unsigned int&);

 //Convert CreditUser info to string
	  std::string to_String();
};
bool check_economy_account_numbers(unsigned int);

#endif