/* calc_wind_chill Copyright 2020
 *
 * Wind chill is defined as
 * w = 33 - [(10(v)^0.5 - v + 10.5)(33 - t)]/23.1
 * Where v is wind speed in m/sec,
 * t is temp in Celsius, s.t. t <= 10.0.
 *
 * Write a function with id GetWindChill. It should accept two double
 * parameters vel and temp and return a double value representing the wind
 * chill. When temp is greater than 10.0, return temp.
 */

#include <cmath>
// using pow
#include <iostream>
using std::cin;
using std::cout;
using std::endl;



/*
 *
 */
double CalcWindChill(double, double);


int main(int argc, char* argv[]) {
  double wind_speed = 3.0, temperature = 0.0;
  double wind_chill = CalcWindChill(wind_speed, temperature);

  cout << "Wind chill is " << wind_chill << endl;

  return 0;
}

double CalcWindChill(double v, double t) {
  double w = 33.0 - ((10.0 * pow(v, 0.5) - v + 10.5)*(33.0 - t))/23.1;
  return w;
}
