#include "stdafx.h"
#include "EmpRepo.h"
#include <fstream>
#include <ios>
#include <iostream>

using namespace std;

EmpRepo::EmpRepo(){}
EmpRepo::~EmpRepo(){}

//Populate a vector<Core*> with all vector from the class
void EmpRepo::read_all_employee(std::vector<Core*>& employees) {
	employees.clear();
	populate_all_vectors();
	for (int i = 0; i != LowEmps.size(); ++i) {
		LowEmp* tempo_low_emp_pointer = &LowEmps[i];
		employees.push_back(tempo_low_emp_pointer);
	}
	for (int i = 0; i != HighEmps.size(); ++i) {
		HighEmp* tempo_high_emp_pointer = &HighEmps[i];
		employees.push_back(tempo_high_emp_pointer);
	}
	for (int i = 0; i != Admins.size(); ++i) {
		Admin* tempo_admin_pointer = &Admins[i];
		employees.push_back(tempo_admin_pointer);
	}
}

//Read Employees from the file and store them into vectors
	void EmpRepo::populate_all_vectors() {

		LowEmps.clear();
		HighEmps.clear();
		Admins.clear();
	ifstream emp_repository;

	emp_repository.open("EmpRepo.txt", ios::in);

	if (emp_repository.fail()) {
		cout << "Unable to or process open the file !" << endl;
		exit(EXIT_FAILURE);
	}
	else {
		string emp_info_line;

		while (getline(emp_repository, emp_info_line))
		{

			vector<string> emo_info;
			emo_info = split(emp_info_line);

			unsigned int account_number = stoi(emo_info[0]);

			if (account_number >= 4000 && account_number <= 9999) {

				LowEmp tempo_low_emp;
				initilizate_low_emp(tempo_low_emp, emo_info);
				LowEmps.push_back(tempo_low_emp);
			}
			else if (account_number >= 101 && account_number <= 3999) {

				HighEmp tempo_high_emp;
				initilizate_high_emp(tempo_high_emp, emo_info);
				HighEmps.push_back(tempo_high_emp);
			}
			else if (account_number >= 1 && account_number <= 100) {
			
				Admin tempo_admin;
				initilizate_admin(tempo_admin, emo_info);
				Admins.push_back(tempo_admin);
			}
			else
				throw domain_error("Invalide account number!");
		}
	}

}

//Store the vectors into the file
void EmpRepo::store_the_data(vector<Core*>& employees) {

	ofstream out_file;

	out_file.open("EmpRepo.txt", ios::out);

	if (out_file.fail()) {
		cout << "Unable to or process open the file !" << endl;
		exit(EXIT_FAILURE);
	}
	else {
		out_file.clear();

		for (int i = 0; i != employees.size(); ++i) {
			out_file << employees[i]->to_String() << endl;
		}

	}
	out_file.close();
}

//Outside the class function
	
	void initilizate_low_emp(LowEmp& emp, vector<string>& emp_info) {
	emp.setAccountNumber(stoi(emp_info[0]));
	emp.setName(emp_info[1]);
}
	void initilizate_high_emp(HighEmp& emp, vector<string>& emp_info) {
		emp.setAccountNumber(stoi(emp_info[0]));
		emp.setName(emp_info[1]);
	}
	void initilizate_admin(Admin& emp, vector<string>& emp_info) {
		emp.setAccountNumber(stoi(emp_info[0]));
		emp.setName(emp_info[1]);
	}