#pragma once
#ifndef GUARD_EmpRepo
#define GUARD_EmpRepo

#include "stdafx.h"
#include "UserRepo.h"
#include "Admin.h"

class EmpRepo:public UserRepo
{
public:
	EmpRepo();
	~EmpRepo();

//Populate a vector<Core*> with all vector from the class
	void read_all_employee(std::vector<Core*>&);

//Read users from file and store them into vectors
	 void populate_all_vectors();

//Store the vectors into the file
	 void store_the_data(std::vector<Core*>&);

//Function to get the vectors
	std::vector<LowEmp> getLowEmps() const { return LowEmps; }
	std::vector<HighEmp> getHighEmps() const  { return HighEmps; }
	std::vector<Admin> getAdmins() const { return Admins; }

protected:
	std::vector<LowEmp> LowEmps;
	std::vector<HighEmp> HighEmps;
	std::vector<Admin> Admins;
};

void initilizate_low_emp(LowEmp& , std::vector<std::string>& );
void initilizate_high_emp(HighEmp& , std::vector<std::string>& );
void initilizate_admin(Admin& , std::vector<std::string>& );

#endif