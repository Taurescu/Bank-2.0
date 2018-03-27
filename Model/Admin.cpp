#pragma once
#include "stdafx.h"
#include "Admin.h"

Admin::Admin() {}
Admin::~Admin() {}

//Function to convert all variable in strings
std::string Admin::to_String() {
	return (Core::to_String() + " " + Admin::access);
}