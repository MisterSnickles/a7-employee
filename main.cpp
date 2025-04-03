#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

#include "list.h"
#include "employee.h"


int main() {

    srand(time(0));

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

        if(ss >> standing >> ssnID >> firstName >> lastName >> position >> department >> salary) {
            int randPos = rand() % (employees.getSize() + 1);
            employees.insert(Employee(standing, ssnID, firstName, lastName, position, department, salary), randPos);
        }
    }

    fin.close();

    cout << "This is the full list of employees. --------------------" << endl;
    employees.print();
    cout << "\n\n" << endl;
    
    while (!employees.isEmpty()) {
        int randRemovePos = rand() % employees.getSize();
        employees.remove(randRemovePos);
        employees.print();
        cout << "Removed from position " << randRemovePos << "\n" << endl;   
    }


}