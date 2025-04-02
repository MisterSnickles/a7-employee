#include "employee.h"
#include <iostream>

using namespace std;

Employee::Employee() {}
Employee::Employee(string st, string i, string f, string l, string p, string d, int s)
    : standing(st), ssnID(i), firstName(f), lastName(l), position(p), department(d), salary(s) {}


void Employee::printEmployee() {
    cout << standing << ", "
         << ssnID << ", "
         << firstName << ", "
         << lastName << ", "
         << department << ", "
         << position << ", "
         << salary << endl;
}