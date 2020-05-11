// Copyright 2020 Matthew Graham
#ifndef INC_EMPLOYEE_H_  // NOLINT
#define INC_EMPLOYEE_H_  // NOLINT
/* Points:
 *   Compilation: 1 point
 *   Style: 2 points
 *   Demographic::first_name() : 1 point
 *   Demographic::last_name() : 1 point
 *   Demographic::date_of_birth() : 1 point
 *   Employee::employee_id() : 1 point (requires child class)
 *   HourlyEmpolyee::pay_rate() : 1.5 point
 *   HourlyEmployee::CalculatePay(double) : 2 point
 *   SalaryEmployee::pay_rate() : 1.5 point
 *   SalaryEmployee::CalculatePay(double) : 2 point
 */


#include <string>

namespace exam3 {

/* The Demographic class provides a base for people in the system. It will be
 * extended by other classes, such as Employee.
 *
 * The class provides a constructor, a virtual destructor, and three accessor
 * methods for the class members passed into the constructor.
 */
class Demographic {
 public:
  Demographic(const std::string& first_name,
              const std::string& last_name,
              const std::string& date_of_birth);
  virtual ~Demographic() {}

  // accessors
  const std::string first_name() const;
  const std::string last_name() const;
  const std::string date_of_birth() const;

 private:
  std::string first_name_;
  std::string last_name_;
  std::string date_of_birth_;
};


/* The Employee class extends the Demographic class and provides a base for two
 * employee types---hourly and salaried. Note that unlike its parent, it is an
 * abstract class.
 *
 * The class provides a constructor which adds a new member---employee id--, a
 * virtual destructor, an accessor for the employee id parameter, and three
 * pure virutal methods which must be implemented by its children. 
 */
class Employee : public Demographic {
 public:
  /* Additional parameter employee_id stored by the Employee class
   */
  Employee(const std::string& first_name,
           const std::string& last_name,
           const std::string& date_of_birth,
           const std::string& employee_id);
  virtual ~Employee() {}

  // accessor
  const std::string employee_id() const;

  /* Must be defined by child
   * Returns the payment unit of a child class, i.e. salary or hourly rate
   */
  virtual double pay_rate() const = 0;

  /* Must be defined by child
   * Calculates and returns the payment based on child class behavior.
   */
  virtual double CalculatePay(double) const = 0;

 private:
  std::string employee_id_;
};


/* HourlyEmplyee extends the Employee class and provides the following methods:
 * - Constructor: accepts 4 const pass-by-reference strings, representing
 *     first_name, last_name, date_of_birth, and employee_id, just like
 *     Employee. It adds a double parameter representing the instance's
 *     hourly rate.
 *
 * - pay_rate: access for the hourly_rate parameter above
 * - CalculatePay: accepts number of hours worked and returns the pay for the
 *     hourly rate based on hours worked.
 */
class HourlyEmployee : public Employee {
 public:
  HourlyEmployee(const std::string& first_name,
           const std::string& last_name,
           const std::string& date_of_birth,
           const std::string& employee_id,
           double hourly_rate);

  double pay_rate() const;

  double CalculatePay(double) const;

 private:
  double hourly_rate_;
};


/* SalaryEmployee extends the Employee class and provides the following methods:
 * - Constructor: accepts 4 const pass-by-reference strings, representing
 *     first_name, last_name, date_of_birth, and employee_id just like
 *     Employee. It adds a double parameter representing the instance's salary.
 *
 * - pay_rate: accessor for the salary parameter above
 * - CalculatePay: accepts a double representing the percentage of the year for
 *   which the salaried employee is paid, e.g. a week is 1/52 of a year
 *   ~1.923%, so if the salaried employee receives a week of pay, then 1.923 is
 *   passed to Calculate.
 */
class SalaryEmployee : public Employee {
 public:
  SalaryEmployee(const std::string& first_name,
           const std::string& last_name,
           const std::string& date_of_birth,
           const std::string& employee_id,
           double salary);

  double pay_rate() const;

  double CalculatePay(double) const;

 private:
  double salary_;
};

}  // namespace exam3

#endif  // NOLINT
