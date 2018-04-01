#pragma once
#ifndef GUARD_UserRepo
#define GUARD_UserRepo

#include "stdafx.h"
#include "GoldUser.h"

class UserRepo
{
public:
	UserRepo();
	virtual ~UserRepo();

//Populate a vector<Core> with all vector from the class
	void read_all_users(std::vector<Core*>&);
	void populate_pointer_vector(std::vector<Core*>&);

//Read users from file and store them into vectors
	virtual void populate_all_vectors();

//Store the vectors into the file
	virtual void store_the_data(std::vector<Core*>&);

//Add user
	void add_user(Core*&);

//Function to get the vectors
	std::vector<BasicUser> getBasicUser() { return BasicUsers; }
	std::vector<CreditUser> getCreditUser() { return CreditUsers; }
	std::vector<GoldUser> getGoldUsers() { return GoldUsers; }

private:
	std::vector<BasicUser> BasicUsers;
	std::vector<CreditUser> CreditUsers;
	std::vector<GoldUser> GoldUsers;
};

void initilizate_basic_user(BasicUser&, std::vector<std::string>&);
void initilizate_credit_user(CreditUser&, std::vector<std::string>&);
void initilizate_gold_user(GoldUser&, std::vector<std::string>&);

std::vector<std::string> split(const std::string&);

#endif
