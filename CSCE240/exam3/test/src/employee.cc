/* Copyright 2020 CSCE240 Exam 3
 */
#include <test/inc/employee.h>
using exam3::Demographic;
using exam3::Employee;
using exam3::HourlyEmployee;
using exam3::SalaryEmployee;
using std::cout;
using std::endl;


int main(int argc, char* argv[]) {
  cout << " Testing Demographic::first_name" << endl;
  if (TestDemographicFirstName())
    cout << "  PASSED" << endl;
  else
    cout << "  FAILED" << endl;

  cout << " Testing Demographic::last_name" << endl;
  if (TestDemographicLastName())
    cout << "  PASSED" << endl;
  else
    cout << "  FAILED" << endl;

  cout << " Testing Demographic::date_of_birth" << endl;
  if (TestDemographicDateOfBirth())
    cout << "  PASSED" << endl;
  else
    cout << "  FAILED" << endl;

  cout << " Testing Employee::employee_id" << endl;
  if (TestEmployeeEmployeeId())
    cout << "  PASSED" << endl;
  else
    cout << "  FAILED" << endl;

  cout << " Testing HourlyEmployee::pay_rate" << endl;
  if (TestHourlyEmployeePayRate(12.50))
    cout << "  PASSED" << endl;
  else
    cout << "  FAILED" << endl;

  cout << " Testing HourlyEmployee::CalculatePay" << endl;
  if (TestHourlyEmployeeCalculatePay(15.75, 35.0))
    cout << "  PASSED" << endl;
  else
    cout << "  FAILED" << endl;

  cout << " Testing SalaryEmployee::pay_rate" << endl;
  if (TestSalaryEmployeePayRate(12.50))
    cout << "  PASSED" << endl;
  else
    cout << "  FAILED" << endl;

  cout << " Testing SalaryEmployee::CalculatePay" << endl;
  if (TestSalaryEmployeeCalculatePay(57000.00, 1.0/26.0))
    cout << "  PASSED" << endl;
  else
    cout << "  FAILED" << endl;

  return 0;
}

bool TestDemographicFirstName() {
  Demographic test_d(kFirst_name, kLast_name, kDate_of_birth);
  return test_d.first_name() == kFirst_name;
}

bool TestDemographicLastName() {
  Demographic test_d(kFirst_name, kLast_name, kDate_of_birth);
  return test_d.last_name() == kLast_name;
}

bool TestDemographicDateOfBirth() {
  Demographic test_d(kFirst_name, kLast_name, kDate_of_birth);
  return test_d.date_of_birth() == kDate_of_birth;
}

bool TestEmployeeEmployeeId() {
  Employee *test_e = new HourlyEmployee(kFirst_name,
                                        kLast_name,
                                        kDate_of_birth,
                                        kEmployee_id,
                                        0.0);
  bool passed = test_e->employee_id() == kEmployee_id;
  delete test_e;

  test_e = new SalaryEmployee(kFirst_name,
                              kLast_name,
                              kDate_of_birth,
                              kEmployee_id,
                              0.0);
  passed = test_e->employee_id() == kEmployee_id && passed;
  delete test_e;

  return passed;
}


bool TestHourlyEmployeePayRate(double hourly_rate) {
  Employee *test_e = new HourlyEmployee(kFirst_name,
                                        kLast_name,
                                        kDate_of_birth,
                                        kEmployee_id,
                                        hourly_rate);
  bool passed = test_e->pay_rate() == hourly_rate;
  delete test_e;
  return passed;
}

bool TestHourlyEmployeeCalculatePay(double hourly_rate,
                                    double hours_worked) {
  Employee *test_e = new HourlyEmployee(kFirst_name,
                                        kLast_name,
                                        kDate_of_birth,
                                        kEmployee_id,
                                        hourly_rate);
  bool passed = fabs(test_e->CalculatePay(hours_worked)
                     - hourly_rate * hours_worked) < kAbs_diff;

  delete test_e;
  return passed;
}


bool TestSalaryEmployeePayRate(double salary) {
  Employee *test_e = new SalaryEmployee(kFirst_name,
                                        kLast_name,
                                        kDate_of_birth,
                                        kEmployee_id,
                                        salary);
  bool passed = test_e->pay_rate() == salary;

  delete test_e;
  return passed;
}

bool TestSalaryEmployeeCalculatePay(double salary,
                                    double annual_percentage) {
  Employee *test_e = new SalaryEmployee(kFirst_name,
                                        kLast_name,
                                        kDate_of_birth,
                                        kEmployee_id,
                                        salary);
  bool passed = fabs(
    test_e->CalculatePay(annual_percentage)
    - salary * 0.01*annual_percentage) < kAbs_diff;

  delete test_e;
  return passed;
}
