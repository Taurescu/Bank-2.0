#pragma once
#include "stdafx.h"
#include "EmpCtrl.h"

//First page 
int intro_first_page();

//Users menu
void menu(UserCtrl&, EmpCtrl&, int&);

//Common actions that every user can do 
void intro_menu();

//Basic user menu
void display_menu_basic_user();
void menu_basic_user(UserCtrl&, int&);

//Credit user
void display_menu_credit_user();
void menu_credit_user(UserCtrl&, int&);

//Gold user
void display_menu_gold_user();
void menu_gold_user(UserCtrl&, int&);

//Employees menu
//Common actions
void intro_emp();

//Low employee menu
void display_menu_low_emp();
void menu_low_emp(UserCtrl&, EmpCtrl&, int&);

//High employee menu
void display_menu_high_menu();
void menu_high_menu(UserCtrl&, EmpCtrl&, int&);

//Admin menu
void display_menu_admin();
void menu_admin(UserCtrl&, EmpCtrl&, int&);


void deposit(UserCtrl&, int&);
void withdrow(UserCtrl&, int&);
void transfer(UserCtrl&, int&);
void balance(UserCtrl&, int&);
void add_economy_account(UserCtrl&, int&);
void delete_economy_account(UserCtrl&, int&);
void transfer_money_to_economy_account(UserCtrl&, int&);
void transfer_money_from_economy_account(UserCtrl&, int&);
void withdrow_credit(UserCtrl&, int&);
void deposit_credit(UserCtrl&, int&);

int& ask_account_number();
void create_account(UserCtrl& );
void delete_account(UserCtrl& );
void delete_low_emp(EmpCtrl& ); 
void delete_emp(EmpCtrl& );
void edit_user(UserCtrl&, int& );
void edit_emp(EmpCtrl& , int& );
void show_user(UserCtrl&, int& );
void show_all_users(UserCtrl& );
void show_all_emp(EmpCtrl& );
void create_emp(EmpCtrl&);
void create_low_emp(EmpCtrl& );