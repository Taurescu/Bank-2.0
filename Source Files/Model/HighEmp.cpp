#pragma once
#include "stdafx.h"
#include "HighEmp.h"


HighEmp::HighEmp(){}
HighEmp::~HighEmp(){}

//Function to convert all variable in strings
std::string HighEmp::to_String() {
	return (Core::to_String() + " " + HighEmp::access);
}