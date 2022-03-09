#include "Employee.h"
#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

void deleteEmployee(map<int, Employee>& mapDeleter, int empnum);
void updateValues(map<int, Employee>& mapUpdater, int empnum, int valueNum);
double weeklyPayrollCalculations(map<int, Employee> &mapping);
double individualNetPay(Employee emp);
bool check_number(string str);


int main() {
	try {

		int option, empnumber;
		string firstName;
		string lastName;
		string address;
		string phonenumber;
		double salary;
		string salaryStr;
		double yearsOfServices;

		map<int, Employee> employeeMap;
		bool goOn = true;

		while (goOn) {
			cout << "Select one of the following options" << endl
				<< "1. Add an employee" << endl
				<< "2. Delete an employee" << endl
				<< "3. Change an employee's data" << endl
				<< "4. Print out employee's data" << endl
				<< "5. Calculate weekly payroll net pay after deductions!" << endl;

			cin >> option;
			cin.ignore(256, '\n');
			while (cin.fail()|| option < 1 || option > 5 ) {
				std::cout << "\a Invalid input, choose a number between 1 and 5" << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> option;
				
				
			}
			while (cin.fail()||option !=1 && employeeMap.empty())
			{
				cout << "Employee list is empty, please add an employee first!" << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> option;
				
			}

			switch (option)
			{
				//add an employee
			case 1: {
				std::cout << "Enter Employee First Name" << endl;
				cin >> firstName;
				cin.ignore(256, '\n');
				while (check_number(firstName))
				{
					std::cout << "\a wrong input, please enter a valid name! " << endl;

					cin >> firstName;
					cin.ignore(256, '\n');
				}
				std::cout << "Enter Employee last Name" << endl;
				cin >> lastName;
				cin.ignore(256, '\n');
				while (check_number(lastName))
				{
					std::cout << "\a wrong input, please enter a valid name! " << endl;

					cin >> lastName;
					cin.ignore(256, '\n');
				}


				std::cout << "Enter Employee Address : Number, Street | Avenue | P.O.City & State & Zip code" << endl;
				cin >> address;
				cin.ignore(256, '\n');
				while (cin.fail())
				{
					std::cout << "\a wrong input, please enter a valid address! " << endl;

					cin >> address;
					cin.ignore(256, '\n');
				}

				std::cout << "Enter Employee Phone number" << endl;
				cin >> phonenumber;
				cin.ignore(256, '\n');
				while (!check_number(phonenumber))
				{
					std::cout << "\a wrong input, please enter a valid number! " << endl;

					cin >> phonenumber;
					cin.ignore(256, '\n');
				}

				std::cout << "Enter Employee Salary" << endl;
				cin >> salary;
				cin.ignore(256, '\n');
				while (cin.fail() || salary < 0)
				{

					std::cout << "\a wrong input, please enter a salary! " << endl;
					cin.clear();
					cin.ignore(256, '\n');
					cin >> salary;

				}

				std::cout << "Enter Employee years of service" << endl;
				cin >> yearsOfServices;
				cin.ignore(256, '\n');
				while (cin.fail()|| yearsOfServices < 0)
				{

					std::cout << "\a wrong input, please enter a entry! " << endl;
					cin.clear();
					cin.ignore(256, '\n');
					cin >> yearsOfServices;
					
					
				}

				
				Employee employee(firstName, lastName, address, phonenumber, salary, yearsOfServices);
				employeeMap.insert(make_pair(employee.getEmployeeNumber(), employee));
				cout << "emp num: "<<employee.getEmployeeNumber()<<endl;
				
			}
				  break;
				  //delete employee	  
			case 2: {

				cout << "enter employee number" << endl;
				cin >> empnumber;

				cin.ignore(256, '\n');
				while ( employeeMap.count(empnumber) != 1)
				{
					std::cout << "\a Employee Doesn't exist, please enter a valid number! " << endl;
					

					cin.ignore(256, '\n');
					cin >> empnumber;
				}

				deleteEmployee(employeeMap, empnumber);
				std::cout << "Employee successfully deleted!" << endl;
			}
				  break;
				  //change employee data
			case 3:
			{
				cout << "enter employee number" << endl;
				cin >> empnumber;

				cin.ignore(256, '\n');
				while ( employeeMap.count(empnumber) != 1)
				{
					std::cout << "\a Employee Doesn't exist, please enter a valid number! " << endl;
					
					cin >> empnumber;
					cin.ignore(256, '\n');

				}
				std::cout << "1.change first name" << endl
					<< "2.change last name" << endl
					<< "3. change address " << endl
					<< "4. change phone number" << endl
					<< "5. change salary" << endl
					<< "6. change years of services" << endl;
				int valueNum;
				cin >> valueNum;
				updateValues(employeeMap, empnumber, valueNum);
				std::cout << "Employee successfully updated!" << endl;

			}
			break;
			//print out employee data
			case 4: {
				cout << "enter employee number" << endl;
				cin >> empnumber;

				cin.ignore(256, '\n');
				while (cin.fail() ||employeeMap.count(empnumber) != 1)
				{
					std::cout << "\a Employee Doesn't exist, please enter a valid number! " << endl;
					cin.clear();
					cin.ignore(256, '\n');
					cin >> empnumber;
					

				}
				cout << employeeMap.at(empnumber).toString();
			}
				  break;
				  // payroll
			case 5: {

				cout << "enter employee number" << endl;
				cin >> empnumber;

				cin.ignore(256, '\n');
				while (cin.fail()||employeeMap.count(empnumber) != 1)
				{
					std::cout << "\a Employee Doesn't exist, please enter a valid number! " << endl;
				
					cin.clear();
					cin.ignore(256, '\n');
					cin >> empnumber;
				}
				std::cout << "Individual net pay: $" << individualNetPay(employeeMap.at(empnumber)) << endl;
				std::cout << "Weekly payroll: $" << weeklyPayrollCalculations(employeeMap) << endl;
			}break;
			default:break;

			}
			cout << "continue? Y/N" << endl;
			string value;
			cin >> value;
			cin.ignore(256, '\n');
			while (value != "Y" && value != "N" && value != "y" && value != "n")
			{
				cout << "Invalid input" << endl;
				cin >> value;
				cin.ignore(256, '\n');

			}
			if (value == "Y" || value == "y")
			{
				goOn = true;
			}
			else goOn = false;


		}

	}


	
	catch (invalid_argument iaex)
	{
		std::cout << "Invalid Syntax";
	}
	catch (string exceptionString)
	{
		std::cout << exceptionString;
	}
	catch (bad_alloc)
	{
		std::cout << "Insufficient memory.\n";
	}
	return 0;
}




void deleteEmployee(map<int, Employee>& mapDeleter, int empnum) {// Employee toBeDeletedEmployee) {

	mapDeleter.at(empnum).countReduce();
	mapDeleter.at(empnum).~Employee();
	mapDeleter.erase(empnum);//toBeDeletedEmployee.getEmployeeNumber());

}


void updateValues(map<int, Employee>& mapUpdater, int empnum, int valueNum) {

	string firstNameUpdate;
	string lastNameUpdate;
	string addressUpdate;
	string phonenumberUpdate;
	double salaryUpdate = 0;
	double yearsOfServicesUpdate = 0;
	switch (valueNum)
	{
	case 1:
	{
		std::cout << "change first name, enter new first name" << endl;
		cin >> firstNameUpdate;
		
		cin.ignore(256, '\n');
		while (check_number(firstNameUpdate))
		{
			std::cout << "\a wrong input, please enter a valid name! " << endl;

			cin >> firstNameUpdate;
			cin.ignore(256, '\n');
		}
		mapUpdater.at(empnum).setEmployeeFirstName(firstNameUpdate); }
	break;
	case 2: {cout << "change last name, enter last name" << endl;
		cin >> lastNameUpdate;

		cin.ignore(256, '\n');
		while (check_number(lastNameUpdate))
		{
			std::cout << "\a wrong input, please enter a valid name! " << endl;

			cin >> lastNameUpdate;
			cin.ignore(256, '\n');
		}
		mapUpdater.at(empnum).setEmployeeLastName(lastNameUpdate); }
		  break;
	case 3: {
		cout << "change address, enter new address" << endl;
		cin >> addressUpdate;
		cin.ignore(256, '\n');
		while (cin.fail())
		{
			std::cout << "\a wrong input, please enter a valid address! " << endl;
			
			cin >> addressUpdate;
			cin.ignore(256, '\n');
		}
		mapUpdater.at(empnum).setEmployeeAddress(addressUpdate);
	}
		  break;

	case 4: {
		std::cout << "change phone number, enter new phone number" << endl;
		cin >> phonenumberUpdate;
		cin.ignore(256, '\n');
		while (!check_number(phonenumberUpdate))
		{
			std::cout << "\a wrong input, please enter a valid number! " << endl;

			cin >> phonenumberUpdate;
			cin.ignore(256, '\n');
		}
		mapUpdater.at(empnum).setEmployeePhoneNumber(phonenumberUpdate); }
		  break;

	case 5: {cout << "change salary, enter new salary" << endl;
		cin >> salaryUpdate;
		cin.ignore(256, '\n');
		while (cin.fail() || salaryUpdate < 0)
		{

			std::cout << "\a wrong input, please enter a salary! " << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> salaryUpdate;

		}
		mapUpdater.at(empnum).setEmployeeSalary(salaryUpdate); }
		  break;

	case 6: {cout << "change years of services, enter new years of services" << endl;
		cin >> yearsOfServicesUpdate;
		while (cin.fail() || yearsOfServicesUpdate < 0)
		{

			std::cout << "\a wrong input, please enter a entry! " << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> yearsOfServicesUpdate;


		}
		mapUpdater.at(empnum).setEmployeeYearsOfServices(yearsOfServicesUpdate); }
		  break;
	default:
		break;
	}

}

double weeklyPayrollCalculations(map<int, Employee> &mapping) {
	double weeklyPayroll = 0;
	std::map<int, Employee>::iterator it = mapping.begin();
	for (it = mapping.begin(); it != mapping.end(); it++)
	{
		weeklyPayroll += individualNetPay(mapping.at(it->first));
	}
	return weeklyPayroll;

}

double individualNetPay(Employee emp) {
	double netSalaryAfterDeductions = 0;
	netSalaryAfterDeductions = emp.getEmployeeSalary() - ((0.15 * emp.getEmployeeSalary()) + (0.0625 * emp.getEmployeeSalary()) + (0.0625 * emp.getEmployeeSalary()));
	return netSalaryAfterDeductions;
}
bool check_number(string str) {
	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i]) == false)
			return false;
	return true;
}
