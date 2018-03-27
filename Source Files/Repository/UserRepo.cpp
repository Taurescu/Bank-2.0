#include "stdafx.h"
#include "UserRepo.h"
#include <fstream>
#include <ios>
#include <iostream>

using namespace std;

UserRepo::UserRepo() {}
UserRepo::~UserRepo() {}

//Populate a vector<Core> with all vector from the class
void UserRepo::read_all_users(std::vector<Core*>& users) {
	UserRepo::populate_all_vectors();
	UserRepo::populate_pointer_vector(users);
	
}
void UserRepo::populate_pointer_vector(std::vector<Core*>& users) {
	
	users.clear();
	for (int i = 0; i != BasicUsers.size(); ++i) {
		BasicUser* tempo_basic_user_pointer = &BasicUsers[i];
		users.push_back(tempo_basic_user_pointer);
	}
	for (int i = 0; i != CreditUsers.size(); ++i) {
		CreditUser* tempo_basic_user_pointer = &CreditUsers[i];
		users.push_back(tempo_basic_user_pointer);
	}
	for (int i = 0; i != GoldUsers.size(); ++i) {
		GoldUser* tempo_basic_user_pointer = &GoldUsers[i];
		users.push_back(tempo_basic_user_pointer);
	}

}

//Read users from file and store them into vectors
void UserRepo::populate_all_vectors() {

	ifstream user_repository;

	user_repository.open("UserRepo.txt", ios::in);

	if (user_repository.fail()) {
		cout << "Unable to or process open the file !" << endl;
		exit(EXIT_FAILURE);
	}
	else {
		string user_info_line;

		while (getline(user_repository, user_info_line))
		{

			vector<string> line;
			line = split(user_info_line);

			unsigned int account_number = stoi(line[0]);

			if (account_number >= 500000 && account_number <= 1500000) {

				BasicUser tempo_basic_user;
				initilizate_basic_user(tempo_basic_user, line);
				BasicUsers.push_back(tempo_basic_user);
			}
			else if (account_number >= 100000 && account_number <= 499999) {
				CreditUser tempo_credit_user;
				initilizate_credit_user(tempo_credit_user, line);
				CreditUsers.push_back(tempo_credit_user);
			}
			else if (account_number >= 10000 && account_number <= 99999) {
				GoldUser tempo_gold_user;
				initilizate_gold_user(tempo_gold_user, line);
				GoldUsers.push_back(tempo_gold_user);
			}
			else
				throw domain_error("Invalide account number!");
		}
	}
	user_repository.close();
}

void UserRepo::add_user(Core*& users) {
	
	if (users->getAccountNumber() >= 500001) {
		BasicUser* basic_user = dynamic_cast<BasicUser*>(users);
		BasicUsers.push_back(*basic_user);
	//	BasicUser* tempo_basic_user_pointer = &BasicUsers[BasicUsers.size() - 1];
		//Users.push_back(&(BasicUsers[BasicUsers.size() - 1]));
	}
	else if (users->getAccountNumber() >= 100000 && users->getAccountNumber() <= 500000) {
		CreditUser* credit_user = dynamic_cast<CreditUser*>(users);
		credit_user->calculate_max_credit();
		CreditUsers.push_back(*credit_user);
	//	CreditUser* tempo_credit_user_pointer = &CreditUsers[CreditUsers.size()-1];
		//Users.push_back(&CreditUsers[CreditUsers.size() - 1]);
	}
	else if (users->getAccountNumber() >= 10000 && users->getAccountNumber() <= 99999) {
		GoldUser* gold_user = dynamic_cast<GoldUser*>(users);
		gold_user->calculate_max_credit();
		GoldUsers.push_back(*gold_user);
	//	GoldUser* tempo_gold_user_pointer = &GoldUsers[GoldUsers.size() - 1];
		//Users.push_back(&GoldUsers[GoldUsers.size() - 1]);
	}
	else
		throw domain_error("Invalide user !");
}


//Store the vectors into the file
void UserRepo::store_the_data(vector<Core*>& users) {

	ofstream out_file;

	out_file.open("UserRepo.txt", ios::out);

	if (out_file.fail()) {
		cout << "Unable to or process open the file !" << endl;
		exit(EXIT_FAILURE);
	}
	else {
		out_file.clear();

		for (int i = 0; i != users.size(); ++i) {
			out_file << users[i]->to_String() << endl;
		}
	}
	out_file.close();
}

//Outside the class functions
void initilizate_basic_user(BasicUser& user, vector<string>& user_info) {

	user.setAccountNumber(stoi(user_info[0]));
	user.setName(user_info[1]);
	user.setBalance(stoi(user_info[2]));

	if (user_info.size() >= 4) {
		string tempo_first_economy_account = user_info[3];
		if (tempo_first_economy_account != " ") {
			unsigned int economy_account = stoi(tempo_first_economy_account);
			user.extend_economy_account(economy_account);
		}
	}
	if (user_info.size() >= 5) {
		string tempo_secound_economy_account = user_info[4];
		if (tempo_secound_economy_account != " ") {
			unsigned int economy_account = stoi(tempo_secound_economy_account);
			user.extend_economy_account(economy_account);
		}
	}
}
void initilizate_credit_user(CreditUser& user, vector<string>& user_info) {
	user.setAccountNumber(stoi(user_info[0]));
	user.setName(user_info[1]);
	user.setBalance(stoi(user_info[2]));
	user.setSalary(stoi(user_info[3]));
	user.setCredit(stoi(user_info[4]));
	if (user_info.size() >= 6) {
		string tempo_first_economy_account = user_info[5];
		if (tempo_first_economy_account != " ") {
			unsigned int economy_account = stoi(tempo_first_economy_account);
			user.extend_economy_account(economy_account);
		}
	}
	if (user_info.size() >= 7) {
		string tempo_secound_economy_account = user_info[6];
		if (tempo_secound_economy_account != " ") {
			unsigned int economy_account = stoi(tempo_secound_economy_account);
			user.extend_economy_account(economy_account);
		}
	}
}
void initilizate_gold_user(GoldUser& user, vector<string>& user_info) {
	user.setAccountNumber(stoi(user_info[0]));
	user.setName(user_info[1]);
	user.setBalance(stoi(user_info[2]));
	user.setSalary(stoi(user_info[3]));
	user.setCredit(stoi(user_info[4]));

	if (user_info.size() >= 6) {
		string tempo_first_economy_account = user_info[5];
		if (tempo_first_economy_account != " ") {
			unsigned int economy_account = stoi(tempo_first_economy_account);
			user.extend_economy_account(economy_account);
		}
	}
	if (user_info.size() >= 7) {
		string tempo_secound_economy_account = user_info[6];
		if (tempo_secound_economy_account != " ") {
			unsigned int economy_account = stoi(tempo_secound_economy_account);
			user.extend_economy_account(economy_account);
		}
	}
	if (user_info.size() >= 8) {
		string tempo_third_economy_account = user_info[7];
		if (tempo_third_economy_account != " ") {
			unsigned int economy_account = stoi(tempo_third_economy_account);
			user.extend_economy_account(economy_account);
		}
	}
}

vector<string> split(const string& s) {
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size()) {
		while (i != s.size() && isspace(s[i]))
			++i;

		string_size j = i;

		while (j != s.size() && !isspace(s[j]))
			++j;

		if (i != j) {
			ret.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return ret;
}

