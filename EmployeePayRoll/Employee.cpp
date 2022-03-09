#include "Employee.h"


int Employee::employeeCount = 0;

void Employee::setEmployeeFirstName(std::string empFirstName)
{
	firstName = empFirstName ;
}

void Employee::setEmployeeLastName(std::string empLastName)
{
	lastName = empLastName;
}

void Employee::setEmployeeAddress(std::string empAddress)
{
	this->address= empAddress;
}

void Employee::setEmployeePhoneNumber(std::string empPhoneNumber)
{
	phoneNumber = empPhoneNumber;
}

void Employee::setEmployeeSalary(double empSalary)
{
	salary = empSalary;
}

void Employee::setEmployeeYearsOfServices(double empYearsOfServices)
{
	yearsOfServices = empYearsOfServices;
}

int Employee::getEmployeeNumber()
{
	return this->employeeNumber;
}

std::string Employee::getEmployeeFirstName()
{
	return this->firstName;
}

std::string Employee::getEmployeeLastName()
{
	return this->lastName;
}

std::string Employee::getEmployeeAddress()
{
	return this->address;
}

std::string Employee::getEmployeePhoneNumber()
{
	return this->phoneNumber;
}

double Employee::getEmployeeSalary()
{
	return this->salary;
}

double Employee::getEmployeeYearsOfServices()
{
	return this->yearsOfServices;
}

