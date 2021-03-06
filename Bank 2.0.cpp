// Main program for management users from a Bank 
// Using main OOP principles (Encapsulation, Abstraction, Inheritance and Polymorphism)
//Designe pattern MVC
// Wrote by Taurescu Alexandru Gabriel
// Date : 03/14/2018

#include "stdafx.h"
#include "Menu.h"
#include <iostream>
#include <stdexcept>



int main()
{
	int account_number;


	
	UserCtrl user_controller;
	EmpCtrl emp_controller;

	try {

	
		account_number = intro_first_page();
		menu(user_controller, emp_controller,account_number);

		
	}
	catch (std::domain_error e) {
		std::cout << e.what() << std::endl;
	
	}

    return 0;
}

