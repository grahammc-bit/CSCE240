// Copyright 2020 Matthew Graham
#include <inc/employee.h>

using std::string;

namespace exam3 {

// Start Demographic
Demographic::Demographic(const string& first_name,
            const string& last_name,
            const string& date_of_birth) {
  first_name_ = first_name;
  last_name_ = last_name;
  date_of_birth_ = date_of_birth;
}

const string Demographic::first_name() const {
  return first_name_;
}

const string Demographic::last_name() const {
  return last_name_;
}

const string Demographic::date_of_birth() const {
  return date_of_birth_;
}
// End Demographic


// Start Employee
  Employee::Employee(const std::string& first_name,
           const string& last_name,
           const string& date_of_birth,
           const string& employee_id) :
           Demographic(first_name, last_name, date_of_birth) {
    employee_id_ = employee_id;
  }

const string Employee::employee_id() const {
  return employee_id_;
}
// End Employee


// Start Hourly Employee
HourlyEmployee::HourlyEmployee(const string& first_name,
         const string& last_name,
         const string& date_of_birth,
         const string& employee_id,
         double hourly_rate) :
         Employee(first_name, last_name, date_of_birth, employee_id) {
  hourly_rate_ = hourly_rate;
}

double HourlyEmployee::pay_rate() const {
  if (hourly_rate_ > 0)
    return hourly_rate_;
  return 0.0;
}

double HourlyEmployee::CalculatePay(double num_hours) const {
  return num_hours * hourly_rate_;
}
// End Hourly Employee


// Start Salary Employee
SalaryEmployee::SalaryEmployee(const string& first_name,
         const string& last_name,
         const string& date_of_birth,
         const string& employee_id,
         double salary) :
         Employee(first_name, last_name, date_of_birth, employee_id) {
  salary_ = salary;
}

double SalaryEmployee::pay_rate() const {
  if (salary_ > 0)
    return salary_;
  return 0.0;
}

double SalaryEmployee::CalculatePay(double percentage) const {
  return salary_ * (percentage / 100);
}
// End Salary Employee

}  // namespace exam3
