#include "stdafx.h"
#include <iostream>
#include "EmpCtrl.h"

using namespace std;

EmpCtrl::EmpCtrl(){
	emp_repository.read_all_employee(Employee);
}
EmpCtrl::~EmpCtrl(){}


//Functions only with admin class access
void EmpCtrl::add_employee(Core* employee_type) {
	
		Employee.push_back(employee_type);
		emp_repository.store_the_data(Employee);
		emp_repository.read_all_employee(Employee);
;
}
void EmpCtrl::delete_employee(int& account_number){
	vector<Core*>::iterator it = EmpCtrl::find_type_element(account_number);
	if (it != Employee.end()) {
		Employee.erase(it);
	}
	else
		throw domain_error("Invalid account number");
}
void EmpCtrl::edite_employee(int& account_number, string& name) {
	vector<Core*>::iterator it = EmpCtrl::find_type_element(account_number);
	if (it != Employee.end()) {
		LowEmp* low_emp = dynamic_cast<LowEmp*>(*it);
		low_emp->setName(name);
	}
		else
			throw domain_error("Invalid account number");
	}


vector<Core*> EmpCtrl::get_all_emplyees() const { return Employee; }

void EmpCtrl::store_data() {
	emp_repository.store_the_data(Employee);
}

//Function that find the element based on account_number
vector<Core*>::iterator EmpCtrl::find_type_element(int& account_number) {
	vector<Core*>::iterator it = Employee.begin();
	for (it; it != Employee.end(); ++it) {
		if ((*it)->getAccountNumber() == account_number)
			return it;
	}
	return it;
}
bool EmpCtrl::is_valid(int& account_number) {
	vector<Core*>::iterator it = find_type_element(account_number);
	if (it != Employee.end())
		return true;
	else
		return false;
}
