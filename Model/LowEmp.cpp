#include "stdafx.h"
#include "LowEmp.h"


LowEmp::LowEmp() {}
LowEmp::~LowEmp() {}

//Function to convert all variable in strings
std::string LowEmp::to_String() {
	return (Core::to_String() + " " + LowEmp::access);
 }