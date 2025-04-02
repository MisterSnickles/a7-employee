#pragma once
#include <string>

class Employee {
private:
    std::string standing;
    std::string firstName;
    std::string lastName;
    std::string position;
    std::string department;
    std::string ssnID;
    int salary;

public:
    Employee();
    Employee(std::string, std::string, std::string, std::string, std::string, std::string, int);
    
    void printEmployee();
};