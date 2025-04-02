#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

#include "list.h"
#include "employee.h"


int main() {

    List<Employee> employees;
    // Open File
    fstream fin;
    string line;
    fin.open("employees.txt", ios::in);

    // If there's an error
    if(!fin.is_open()) {
        cout << "Error: Could not open file." << endl;
        return 1;
    }

    // read from file : store variables arrival, duration, type, plate : construct car object from those variables
    // depatureTime is calculated during car object construction
    while(getline(fin, line)) {
        stringstream ss(line);
        string standing, ssnID, firstName, lastName, id, position, department;
        int salary;

        string str_salary = to_string(salary);

        if(ss >> standing >> ssnID >> firstName >> lastName >> position >> department >> salary) {
            employees.push(Employee(standing, ssnID, firstName, lastName, position, department, salary));
        }
    }

    
    employees.print();
    
    for (int i = 0; i < 8; i++) {
        employees.pop();
    }

    cout << "\n" << endl;
    // should be 7 less employees with popping from last input starting with megan and ending with natalie
    employees.print();

}