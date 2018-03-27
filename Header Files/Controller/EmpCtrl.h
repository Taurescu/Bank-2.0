#pragma once
#ifndef GUARD_EmpCtrl
#define GUARD_EmpCtrl

#include "stdafx.h"
#include "EmpRepo.h"
#include "UserCtrl.h"


class EmpCtrl:public UserCtrl
{
public:
	EmpCtrl();
	~EmpCtrl();

	//Functions only with admin class access
	void add_employee(Core*);
	void delete_employee(int&);
	void edite_employee(int&, std::string&);
	std::vector<Core*> get_all_emplyees() const;

	std::vector<Core*>::iterator find_type_element(int&);
	bool is_valid(int&);

	//Store and save the data
	void store_data();

private:
	std::vector<Core*> Employee;
	EmpRepo emp_repository;
	
};
#endif
