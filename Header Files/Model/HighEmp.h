#pragma once
#pragma once
#ifndef GUARD_HighEmp
#define GUARD_HighEmp

#include "stdafx.h"
#include "LowEmp.h"



class HighEmp:public LowEmp {
public:
	HighEmp();
	~HighEmp();

//Function to convert all variable in strings
	 std::string to_String();

private:
	std::string access = "High Access!";
};


#endif