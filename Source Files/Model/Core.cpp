#include "stdafx.h"
#include "Core.h"

using namespace std;

Core::Core() : account_number(0), name(" ") {}
Core::~Core(){}

string Core::to_String() {

	return (std::to_string(account_number) + " " + name);
}