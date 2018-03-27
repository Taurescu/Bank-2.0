#include "stdafx.h"
#include "Menu.h"
#include <iostream>

using namespace std;

// First page
int intro_first_page() {
	std::cout << "====================================================\n="
		<< "\t \t  BANK \t\t\t\t   ="
		<< "\n\n=\t\tMANAGEMENT \t\t\t   ="
		<< "\n\n=\t\t SYSTEM\t\t\t\t   ="
		<< "\n====================================================\n"
		<< " \nPlease Enter Your Account Number : ";

	int account_number;
	cin >> account_number;
	return account_number;

}

//Users menu
void menu(UserCtrl& user, EmpCtrl& employee, int& account_number) {

	if (user.is_valid(account_number) || employee.is_valid(account_number)) {
		system("CLS");

		if (account_number >= 1 && account_number <= 100) {
			intro_emp();
			display_menu_admin();
			menu_admin(user, employee, account_number);
		}
		else if (account_number >= 101 && account_number <= 3999) {
			intro_emp();
			display_menu_high_menu();
			menu_high_menu(user, employee, account_number);
		}
		else if (account_number >= 4000 && account_number <= 9999) {
			intro_emp();
			display_menu_low_emp();
			menu_low_emp(user, employee, account_number);
		}
		else if (account_number >= 10000 && account_number <= 99999) {
			intro_menu();
			display_menu_gold_user();
			menu_gold_user(user, account_number);
		}
		else if (account_number >= 100000 && account_number <= 500000) {
			intro_menu();
			display_menu_credit_user();
			menu_credit_user(user, account_number);
		}
		else if (account_number >= 500001) {
			intro_menu();
			display_menu_basic_user();
			menu_basic_user(user, account_number);
		}
		else
			throw domain_error("Incorect account number!");
	}
	else {
		cout << "Incorect account number!" << endl;
	}
}
//Common actions that every user can do 
void intro_menu() {
	system("CLS");
	std::cout << "====================================================\n="
		<< "\t   Hi, Welcome to your account! \t   ="
		<< "\n\n=\tHere is a list of transactions \t\t   ="
		<< "\n\n=\t\t that you can do : \t\t   ="
		<< "\n====================================================\n";
}


//Basic user menu
void display_menu_basic_user() {

	cout << " 01. Deposit amount\n"
		<< " 02. Withdrow amount\n"
		<< " 03. Transfer money\n"
		<< " 04. Balance\n"
		<< " 05. Add economy account\n"
		<< " 06. Delete economy account\n"
		<< " 07. Transfer money to economy account\n"
		<< " 08. Transfer money from economy account\n"
		<< " 09. Exit\n"
		<< "Select Your Option<1-9>\n";
}
void menu_basic_user(UserCtrl& user, int& account_number) {
	short option;
	do {
		cin >> option;
		switch (option) {
		case 1:
			deposit(user, account_number);
			break;
		case 2:
			withdrow(user, account_number);
			break;
		case 3:
			transfer(user, account_number);
			break;
		case 4:
			balance(user, account_number);
			break;
		case 5:
			add_economy_account(user, account_number);
			break;
		case 6:
			delete_economy_account(user, account_number);
			break;
		case 7:
			transfer_money_to_economy_account(user, account_number);
			break;
		case 8:
			transfer_money_from_economy_account(user, account_number);
			break;
		case 9:
			user.store_data();
			break;
		default:
			system("CLS");
			cout << "You entered a wrong number!" << endl;
		}
		system("PAUSE");
		intro_menu();
		display_menu_basic_user();
	} while (option != 9);
}

//Credit user
void display_menu_credit_user() {
	cout << " 01. Deposit money\n"
		<< " 02. Withdrow money\n"
		<< " 03. Transfer money\n"
		<< " 04. Balance\n"
		<< " 05. Add economy account\n"
		<< " 06. Delete economy account\n"
		<< " 07. Transfer money to economy account\n"
		<< " 08. Transfer money from economy account\n"
		<< " 09. Withdrow credit\n"
		<< " 10. Deposit credit\n"
		<< " 11. Exit\n"
		<< "Select Your Option<1-11>\n";
}
void menu_credit_user(UserCtrl& user, int& account_number) {
	short option;
	do {
		cin >> option;
		switch (option) {
		case 1:
			deposit(user, account_number);
			break;
		case 2:
			withdrow(user, account_number);
			break;
		case 3:
			transfer(user, account_number);
			break;
		case 4:
			balance(user, account_number);
			break;
		case 5:
			add_economy_account(user, account_number);
			break;
		case 6:
			delete_economy_account(user, account_number);
			break;
		case 7:
			transfer_money_to_economy_account(user, account_number);
			break;
		case 8:
			transfer_money_from_economy_account(user, account_number);
			break;
		case 9:
			withdrow_credit(user, account_number);
			break;
		case 10:
			deposit_credit(user, account_number);
			break;
		case 11:
			user.store_data();
			break;
		default:
			system("CLS");
			cout << "You entered a wrong number!" << endl;
			
		}
		system("PAUSE");
		intro_menu();
		display_menu_credit_user();
	} while (option != 11);
}

//Gold user
void display_menu_gold_user() {
	cout << " 01. Deposit money\n"
		<< " 02. Withdrow money\n"
		<< " 03. Transfer money\n"
		<< " 04. Balance\n"
		<< " 05. Add economy account\n"
		<< " 06. Delete economy account\n"
		<< " 07. Transfer money to economy account\n"
		<< " 08. Transfer money from economy account\n"
		<< " 09. Withdrow credit\n"
		<< " 10. Deposit credit\n"
		<< " 11. Exit\n"
		<< "Select Your Option<1-11>\n";
}
void menu_gold_user(UserCtrl& user, int& account_number) {
	short option;
	do {
		cin >> option;
		switch (option) {
		case 1:
			deposit(user, account_number);
			break;
		case 2:
			withdrow(user, account_number);
			break;
		case 3:
			transfer(user, account_number);
			break;
		case 4:
			balance(user, account_number);
			break;
		case 5:
			add_economy_account(user,account_number);
			break;
		case 6:
			delete_economy_account(user, account_number);
			break;
		case 7:
			transfer_money_to_economy_account(user, account_number);
			break;
		case 8:
			transfer_money_from_economy_account(user, account_number);
			break;
		case 9:
			withdrow_credit(user, account_number);
			break;
		case 10:
			deposit_credit(user, account_number);
			break;
		case 11:
			user.store_data();
			break;

		default:
			system("CLS");
			cout << "You entered a wrong number!" << endl;
		}
		system("PAUSE");
		intro_menu();
		display_menu_gold_user();
	} while (option != 11);
}

//Employees menu
//Common actions
void intro_emp() {
	system("CLS");
	cout << "====================================================\n="
		<< "\t \t  BANK \t\t\t\t   ="
		<< "\n\n=\t\tMANAGEMENT \t\t\t   ="
		<< "\n\n=\t\t SYSTEM\t\t\t\t   ="
		<< "\n\n=\tHere is the list of transactions \t   ="
		<< "\n\n=\t\t that you can do : \t\t   ="
		<< "\n====================================================\n";
}

//Low employee menu
void display_menu_low_emp() {
	cout << " 01. Create a new user account\n"
		<< " 02. Delete a user account\n"
		<< " 03. Show user info\n"
		<< " 04. Edit user\n"
		<< " 05. Deposit money to user\n"
		<< " 06. Withdrow money for user\n"
		<< " 07. Add economy account\n"
		<< " 08. Delete economy account\n"
		<< " 09. Transfer money to economy account\n"
		<< " 10. Transfer money from economy account\n"
		<< " 11. Show all users\n"
		<< " 12. Exit\n"
		<< "Select Your Option<1-12>\n";
}
void menu_low_emp(UserCtrl& user, EmpCtrl& employee, int& account_number) {
	short option;
	do {
		cin >> option;
		switch (option) {
		case 1:
			create_account(user);
			break;
		case 2:
			delete_account(user);
			break;
		case 3:
			show_user(user, ask_account_number());
			break;
		case 4:
			edit_user(user, ask_account_number());
			break;
		case 5:
			deposit(user, ask_account_number());
			break;
		case 6:
			withdrow(user, ask_account_number());
			break;
		case 7:
			add_economy_account(user, ask_account_number());
			break;
		case 8:
			delete_economy_account(user, ask_account_number());
			break;
		case 9:
			transfer_money_to_economy_account(user, ask_account_number());
			break;
		case 10:
			transfer_money_from_economy_account(user, ask_account_number());
			break;
		case 11:
			show_all_users(user);
			break;
		case 12:
			employee.store_data();
			user.store_data();
			break;

		default:
			system("CLS");
			cout << "You entered a wrong number!" << endl;
		}
		system("PAUSE");
		intro_emp();
		display_menu_low_emp();
	} while (option != 12);
}

//High employee menu
void display_menu_high_menu() {
	cout << " 01. Create a new user account\n"
		<< " 02. Delete a user account\n"
		<< " 03. Show user info\n"
		<< " 04. Edit user\n"
		<< " 05. Deposit money to user\n"
		<< " 06. Withdrow money for user\n"
		<< " 07. Add economy account\n"
		<< " 08. Delete economy account\n"
		<< " 09. Transfer money to economy account\n"
		<< " 10. Transfer money from economy account\n"
		<< " 11. Show all users\n"
		<< " 12. Create new low employee account\n"
		<< " 13. Deleate a low employee account\n"
		<< " 14. Edit low employee account\n"
		<< " 15. Exit\n"
		<< "Select Your Option<1-15>\n";
}
void menu_high_menu(UserCtrl& user, EmpCtrl& employee, int& account_number) {
	short option;
	do {
		cin >> option;
		switch (option) {
		case 1:
			create_account(user);
			break;
		case 2:
			delete_account(user);
			break;
		case 3:
			show_user(user, ask_account_number());
			break;
		case 4:
			edit_user(user, ask_account_number());
			break;
		case 5:
			deposit(user, ask_account_number());
			break;
		case 6:
			withdrow(user, ask_account_number());
			break;
		case 7:
			add_economy_account(user, ask_account_number());
			break;
		case 8:
			delete_economy_account(user, ask_account_number());
			break;
		case 9:
			transfer_money_to_economy_account(user, ask_account_number());
			break;
		case 10:
			transfer_money_from_economy_account(user, ask_account_number());
			break;
		case 11:
			show_all_users(user);
			break;
		case 12:
			create_low_emp(employee);
			break;
		case 13:
			delete_low_emp(employee);
			break;
		case 14:
			edit_emp(employee, ask_account_number());
			break;
		case 15:
			
			employee.store_data();
			user.store_data();
			break;
		default:
			system("CLS");
			cout << "You entered a wrong number!" << endl;
		}
		system("PAUSE");
		intro_emp();
		display_menu_high_menu();
	} while (option != 15);
}

//Admin menu
void display_menu_admin() {
	cout << " 01. Create a new user account\n"
		<< " 02. Delete a user account\n"
		<< " 03. Show user info\n"
		<< " 04. Edit user\n"
		<< " 05. Deposit money to user\n"
		<< " 06. Withdrow money for user\n"
		<< " 07. Add economy account\n"
		<< " 08. Delete economy account\n"
		<< " 09. Transfer money to economy account\n"
		<< " 10. Transfer money from economy account\n"
		<< " 11. Show all users\n"
		<< " 12. Create new employee account\n"
		<< " 13. Deleate a employee account\n"
		<< " 14. Edit employee account\n"
		<< " 15. Show all employees\n"
		<< " 16. Exit\n"
		<< "Select Your Option<1-16>\n";
}
void menu_admin(UserCtrl& user, EmpCtrl& employee, int& account_number) {
	short option;
	do {
		cin >> option;
		switch (option) {
		case 1:
			create_account(user);
			break;
		case 2:
			delete_account(user);
			break;
		case 3:
			show_user(user, ask_account_number());
			break;
		case 4:
			edit_user(user, ask_account_number());
			break;
		case 5:
			deposit(user, ask_account_number());
			break;
		case 6:
			withdrow(user, ask_account_number());
			break;
		case 7:
			add_economy_account(user, ask_account_number());
			break;
		case 8:
			delete_economy_account(user, ask_account_number());
			break;
		case 9:
			transfer_money_to_economy_account(user, ask_account_number());
			break;
		case 10:
			transfer_money_from_economy_account(user, ask_account_number());
			break;
		case 11:
			show_all_users(user);
			break;
		case 12:
			create_emp(employee);
			break;
		case 13:
			delete_emp(employee);
			break;
		case 14:
			edit_emp(employee, ask_account_number());
				break;
		case 15:
			show_all_emp(employee);
			break;
		case 16:
			employee.store_data();
			user.store_data();
			break;
		default:
			system("CLS");
			cout << "You entered a wrong number!" << endl;
		}
		system("PAUSE");
		intro_emp();
		display_menu_admin();
	} while (option != 16);
}


void deposit(UserCtrl& user, int& account_number) {
	try {
		system("CLS");
		unsigned int money;
		cout << "Enter the money :";
		cin >> money;
		user.deoposit_money(account_number, money);
	}
	catch (domain_error e) {
		cout << e.what() << endl;
	}
}
void withdrow(UserCtrl& user, int& account_number) {
	try{
		system("CLS");
	unsigned int money;
	cout << "Enter the money :";
	cin >> money;
	user.withdrow_money(account_number, money);
	}
	catch (domain_error e) {
		cout << e.what() << endl;
	}
}
void transfer(UserCtrl& user, int& account_number) {
	try {
		system("CLS");
	int reciver_account_number;
	cout << "Enter account number of the reciver:";
	cin >> reciver_account_number;
	unsigned int money;
	cout << "Enter the amount you want to transfer :";
	cin >> money;
	user.transfer_money(account_number, reciver_account_number, money);
	}
	catch (domain_error e) {
		cout << e.what() << endl;
		
	}
}
void balance(UserCtrl& user, int& account_number) {
try{	system("CLS");
	cout << "Your curent balance is: ";
	user.getbalance(account_number);
}
catch (domain_error e) {
	cout << e.what() << endl;
}
}
void add_economy_account(UserCtrl& user, int& account_number) {
	try{
		system("CLS");
	user.add_economy_account(account_number);
	std::cout << "You have added an new economy account!" << endl;

	}
	catch (domain_error e) {
		std::cout << e.what() << endl;
	
	}
}
void delete_economy_account(UserCtrl& user, int& account_number) {
	try{
		system("CLS");
	user.delete_economy_account(account_number);
	cout << "You have deletead an economy account!" << endl;

	}
	catch (domain_error e) {
		cout << e.what() << endl;

	}
}
void transfer_money_to_economy_account(UserCtrl& user, int& account_number) {
	try{
		system("CLS");
	unsigned int money;
	int economy_account;
	cout << "Enter the number of economy account: ";
	cin >> economy_account;
	cout << "\nEnter the money :";
	cin >> money;
	user.transfer_money_to_economy_account(account_number, economy_account, money);
	}
	catch (domain_error e) {
		cout << e.what() << endl;
	}
}
void transfer_money_from_economy_account(UserCtrl& user, int& account_number) {
	try{
	system("CLS");
	unsigned int money;
	int economy_account;
	cout << "Enter the number of economy account: ";
	cin >> economy_account;
	cout << "\nEnter the money :";
	cin >> money;
	user.transfer_money_from_economy_account(account_number, economy_account, money);
	}
	catch (domain_error e) {
		cout << e.what() << endl;
		
	}
}
void withdrow_credit(UserCtrl& user, int& account_number) {
	try{
		system("CLS");
	int money;
	cout << "Enter the money :";
	cin >> money;
	user.withdrow_credit(account_number, money);
	}
	catch (domain_error e) {
		cout << e.what() << endl;
		
	}
}
void deposit_credit(UserCtrl& user, int& account_number) {
	try{
		system("CLS");
	int money;
	cout << "Enter the money :";
	cin >> money;
	user.deposit_creit(account_number, money);
	}
	catch (domain_error e) {
		cout << e.what() << endl;
	}
}




int& ask_account_number() {
	system("CLS");
	cout << "Enter the account number: ";
	static int account_number;
	cin >> account_number;

	return account_number;
}
void create_account(UserCtrl& user){
	try{
	system("CLS");
	short type;
	int account_number, balance, salary, credit;
	string name;
	cout << "What type of user do you want to create ?\n"
		<< "1. Basic User\n"
		<< "2. Credit User\n"
		<< "3. Gold User\n"
		<< "Select Your Option<1-3>\n" << endl;
	cin >> type;

	cout << "Enter the account number: ";
	cin >> account_number;
	if (!user.is_valid(account_number)) {

		switch (type) {
		case 1:
			if (account_number >= 500001) {
				BasicUser temp_basic;
				BasicUser* temp;

				temp_basic.setAccountNumber(account_number);

				cout << "Enter the name: ";
				cin >> name;
				temp_basic.setName(name);

				cout << "Enter the balance: ";
				cin >> balance;
				temp_basic.setBalance(balance);

				temp = &temp_basic;

				user.add_User(temp);


			}
			else
				throw domain_error("Incorect account number!");

			break;
		case 2:
			if (account_number >= 100000 && account_number <= 500000) {
				CreditUser temp_credit;
				CreditUser* temp_;
				temp_credit.setAccountNumber(account_number);

				cout << "Enter the name: ";
				cin >> name;
				temp_credit.setName(name);

				cout << "Enter the balance: ";
				cin >> balance;
				temp_credit.setBalance(balance);

				cout << "Enter the salary:";
				cin >> salary;
				temp_credit.setSalary(salary);

				temp_ = &temp_credit;

				user.add_User(temp_);


			}
			else
				throw domain_error("Incorect account number!");
			break;
		case 3:
			if (account_number >= 10000 && account_number <= 99999) {

				GoldUser temp_gold;
				GoldUser* temp__;

				temp_gold.setAccountNumber(account_number);

				cout << "Enter the name: ";
				cin >> name;
				temp_gold.setName(name);

				cout << "Enter the balance: ";
				cin >> balance;
				temp_gold.setBalance(balance);

				cout << "Enter the salary:";
				cin >> salary;
				temp_gold.setSalary(salary);

				temp__ = &temp_gold;

				user.add_User(temp__);

			}
			else
				throw domain_error("Incorect account number!");
			break;
		default:
			cout << "You've entered a wrong number!" << endl;
			break;
		}
	}else
		throw domain_error("Account number already used");
	account_number = 0;
	balance = 0;
	salary = 0;
	credit = 0;
	name = "0";
	}
	catch (domain_error e) {
		cout << e.what() << endl;
		
	}
}
void delete_account(UserCtrl& user) {
	try{
		system("CLS");
	user.delete_User(ask_account_number());
	cout << "The user has been delated!" << endl;
	
	}
	catch (domain_error e) {
		cout << e.what() << endl;
		
	}
}
void delete_low_emp(EmpCtrl& employee) {
	try{
		system("CLS");
		int account_number = ask_account_number();
		if (account_number >= 4000 && account_number <= 9999) {
			employee.delete_employee(account_number);
			cout << "The user has been delated!" << endl;
			
		}
		else
		throw domain_error("You dont have acces to delete that account!");
	}
	catch (domain_error e) {
		cout << e.what() << endl;
	
	}
}
void delete_emp(EmpCtrl& employee) {
	try{
		system("CLS");
	employee.delete_employee(ask_account_number());
	cout << "The user has been delated!" << endl;

	}
	catch (domain_error e) {
		cout << e.what() << endl;
	
	}
}
void edit_user(UserCtrl& user, int& account_number) {
	try {
		string name;
		int salary;
		if (account_number >= 500001) {
			int salary;
			std::cout << "Enter the new name: ";
			std::cin >> name;
			user.edit_User(account_number, name, salary);
			std::cout << "The user has been change !" << endl;
			system("Pause");
		}
		else if (account_number >= 10000 && account_number <= 500000) {

			std::cout << "Enter the new name: ";
			std::cin >> name;
			std::cout << "Enter the new salary: ";
			std::cin >> salary;
			user.edit_User(account_number, name, salary);
			std::cout << "The user has been change !" << endl;
			system("Pause");
		}
		else
			throw domain_error("Invalide account number!");
	}
	catch (domain_error e) {
		std::cout << e.what() << endl;
		
	}
}
void edit_emp(EmpCtrl& employee, int& account_number) {
	try{
		string name;
	cout << " Enter the new name: ";
	cin >> name;
	employee.edite_employee(account_number, name);
	cout << "The name has been change !" << endl;
	
	}
	catch (domain_error e) {
		cout << e.what() << endl;
		
	}
}
void show_user(UserCtrl& user, int& account_number) {
	if (user.is_valid(account_number)) {
		try {
			system("CLS");
			cout << "\n\n\t\tACCOUNT\n\n"
				"====================================================\n"
				"A/c no.      NAME      \n"
				"====================================================\n";
			cout << user.show_user(account_number) << endl;

		}
		catch (domain_error e) {
			cout << e.what() << endl;

		}
	}
	else {
		cout << "Incorect account number!" << endl;
	}
}
void show_all_users(UserCtrl& user) {
	try{
		system("CLS");
		cout << "\n\n\t\tACCOUNT\n\n"
		"====================================================\n"
		"A/c no.      NAME           \n"
		"====================================================\n";
	for (auto&& i : user.get_all_users()) {
		cout << i->to_String() << endl;
	}

	}
	catch (domain_error e) {
		cout << e.what() << endl;
		
	}
}
void show_all_emp(EmpCtrl& employee) {
	try{
		system("CLS");
		cout << "\n\n\t\tACCOUNT\n\n"
		"==============================\n"
		"A/c no./NAME/Type \n "
		"=============================\n";
	for (auto&& i : employee.get_all_emplyees()) {
		cout << i->to_String() << endl;
	}
	
	}
	catch (domain_error e) {
		cout << e.what() << endl;
	
	}
}
void create_emp(EmpCtrl& employee){
	try{
		system("CLS");
	short type;
	int account_number;
	string name;

	cout << "What type of user do you want to create ?\n"
		<< "1. Low acces employee\n"
		<< "2. High acces employee\n"
		<< "3. Admin\n"
		<< "Select Your Option<1-3>\n" << endl;
	cin >> type;

	cout << "Enter the account number: ";
	cin >> account_number;

	if (!employee.is_valid(account_number)) {
		switch (type) {
		case 1:
			if (account_number >= 4000 && account_number <= 9999) {
				LowEmp temp_low_emp;
				LowEmp* temp;
				temp_low_emp.setAccountNumber(account_number);

				cout << "Enter the name: ";
				cin >> name;
				temp_low_emp.setName(name);

				temp = &temp_low_emp;

				employee.add_employee(temp);

				temp_low_emp.~LowEmp();
			}
			else
				throw domain_error("Low employees have account number between [4000-10000) ");

			break;
		case 2:
			if (account_number >= 101 && account_number <= 3999) {

				HighEmp temp_high_emp;
				HighEmp* temp_;
				cout << "Enter the account number: ";
				cin >> account_number;
				temp_high_emp.setAccountNumber(account_number);

				cout << "Enter the name: ";
				cin >> name;
				temp_high_emp.setName(name);

				temp_ = &temp_high_emp;

				employee.add_employee(temp_);

				temp_high_emp.~HighEmp();
			}
			else
				throw domain_error("High employees have account number between (100-4000) ");
			break;
		case 3:
			if (account_number >= 1 && account_number <= 100) {

				Admin temp_admin;
				Admin* temp__;
				cout << "Enter the account number: ";
				cin >> account_number;
				temp_admin.setAccountNumber(account_number);

				cout << "Enter the name: ";
				cin >> name;
				temp_admin.setName(name);

				temp__ = &temp_admin;

				employee.add_employee(temp__);

				temp_admin.~Admin();
			}
			else
				throw domain_error("Admin have account number between (0-100] ");
			break;
		default:
			cout << "You've entered a wrong number!" << endl;
			break;
		}
		account_number = 0;
		name = "0";
	}
	else
		throw domain_error("Account number already used");
	}
	catch (domain_error e) {
		cout << e.what() << endl;
		
	}

}
void create_low_emp(EmpCtrl& employee) {
	try {
		system("CLS");
		int account_number;
		cout << "Enter the account number: ";
		cin >> account_number;
		if (!employee.is_valid(account_number)) {
			if (account_number >= 4000 && account_number <= 9999) {
				string name;

				LowEmp temp_low_emp;

				LowEmp* temp;

				temp_low_emp.setAccountNumber(account_number);

				cout << "Enter the name: ";
				cin >> name;
				temp_low_emp.setName(name);

				temp = &temp_low_emp;

				employee.add_employee(temp);

				account_number = 0;
				name = "0";
				temp_low_emp.~LowEmp();
			}
			else
				throw domain_error("You have acces to create only Low Employee accounts!");
		}
		else
			throw domain_error("Account number already used");
	}
	catch (domain_error e) {
		cout << e.what() << endl;
	
	}
}
