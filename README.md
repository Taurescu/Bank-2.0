# Bank-2.0
Bank management application

Using main OOP principles (Encapsulation, Abstraction, Inheritance and Polymorphism)
Designe pattern MVC

The program read user accounts and employees account from 2 files and store them.
For the first run of the program you need to insert manualy at least one account into the file so that you can log in with it.

There are 3 types of user(Basic User, Credit User and Gold User) and 3 types of employees (Low access employee, High access employee
  and Admin).Every type of account have different functions that can do.
  
  Data stored in the file for every account:
  
  1) Basic User:
     ("Account number"+" "+"Name"+" "+"Balance"+" "+"Economy account 1"+" "+"Economy account 2")
  
  2) Credit User:
     ("Account number"+" "+"Name"+" "+"Balance"+" "+"Salary"+" "+"Credit"+" "+"Economy account 1"+" "+"Economy account 2")
    
  3) Gold User:
     ("Account number"+" "+"Name"+" "+"Balance"+" "+"Salary"+" "+"Credit"+" "+"Economy account 1"+" "+"Economy account 2"+
                                                                                                          " "+"Economy account 3")
  4) All Employees:
     ("Account number"+" "+"Name")
  
      Mandatory fields:
      
    Every account :
       Account number - a number unique for every user for authentication(At the start of the proggram you need to enter your account number
        to enter in your account).
      
       Name - Name for every account(there can be accounts with the same name, but not with the same account number)
       
    Users:
       Balance - the amount of money every user have(the user can add/withdrow/ transfer and a lot more from this field)
    
     Credit and Gold:
     
       -Salary - this is a number that represent the salary of the user and it's used to calculate the amount of credit the user can use
       
       -Credit - this is calculated based on salary and the user can use this money separated from Balance
       
        Obtional fields:
        
        Economy accounts - every user can create or delete theyr economy account and they can be used if they want to store
                              the money in them for savings. You can't withdrow from those account but you can transfer freely
                              to and from balance.
       
     
        
    
