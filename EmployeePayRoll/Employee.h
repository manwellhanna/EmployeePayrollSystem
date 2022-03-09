#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <iomanip>
#include <ostream>	
#include<sstream>

class Employee {
	 static int employeeCount;
private:
	
	int employeeNumber;
	std::string firstName;
	std::string lastName;
	std::string address;
	std::string phoneNumber;
	double salary;
	double yearsOfServices;


public:

	//default constructor
	Employee() {
		employeeCount++;
		employeeNumber = employeeCount ;
		firstName = "";
		lastName = "";
		address = "";
		phoneNumber = "";
		salary = 0;
		yearsOfServices=0;
	}

	//Constructor
	Employee(std::string empFirstName, std::string empLastName, std::string empAddress, std::string empPhoneNumber,
		double empSalary, double empYearsOfServices) {
		employeeCount++;
		employeeNumber = employeeCount;
		setEmployeeFirstName(empFirstName);
		setEmployeeLastName(empLastName);
		setEmployeeAddress(empAddress);
		setEmployeePhoneNumber(empPhoneNumber);
		setEmployeeSalary(empSalary);
		setEmployeeYearsOfServices(empYearsOfServices);
	}

	// destructor
		/*~Employee()
	{
			employeeCount--;
	}*/

	//setters
	void setEmployeeFirstName(std::string empFirstName);
	void setEmployeeLastName(std::string empLastName);
	void setEmployeeAddress(std::string empAddress);
	void setEmployeePhoneNumber(std::string empPhoneNumber);
	void setEmployeeSalary(double empSalary);
	void setEmployeeYearsOfServices(double empYearsOfServices);

	//getters
	int getEmployeeNumber();
	std::string getEmployeeFirstName();
	std::string getEmployeeLastName();
	std::string getEmployeeAddress();
	std::string getEmployeePhoneNumber();
	double getEmployeeSalary();
	double getEmployeeYearsOfServices();

	//To String 
	std::string toString()
	{
		std::stringstream ss;
		ss << "Employee Number: " << this->getEmployeeNumber() << std::endl
			<< "First Name: " << this->getEmployeeFirstName() << std::endl 
			<< "Last Name: " << this->getEmployeeLastName() << std::endl
			<< "Address: " << this->getEmployeeAddress() << std::endl
			<< "Phone number: " << this->getEmployeePhoneNumber() << std::endl
			<< "Salary: " << this->getEmployeeSalary() << std::endl
			<< "Years Of Service: " << this->getEmployeeYearsOfServices() << std::endl;
		return ss.str();
	}
	void countReduce() {
		employeeCount--;
	}

};

#endif // !EMPLOYEE.H
