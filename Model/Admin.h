#pragma once
#pragma once
#ifndef GUARD_Admin
#define GUARD_Admin

#include "stdafx.h"
#include "HighEmp.h"


class Admin:public HighEmp {
public:
	Admin();
	~Admin();

//Function to convert all variable in strings
	 std::string to_String();

private:
	std::string access = "Full Access!";
};

#endif