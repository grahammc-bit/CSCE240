// Copyright 2020 Matthew Graham
#ifndef INC_SMART_APPLIANCE_H_  // NOLINT
#define INC_SMART_APPLIANCE_H_  // NOLINT
/* Points:
 *   Compilation: 1 point
 *   Style: 2 points
 *   SmartLight::Activate: 2 points
 *   SmartLight::Deactivate: 2 points
 *   SmartLight::Set: 5 points
 *   SmartThermostat::Activate: 2 points
 *   SmartThermostat::Deactivate: 2 points
 *   SmartThermostat::Set: 4 points
 */


#include <string>
#include <sstream>
#include <iostream>
using std::stringstream;


namespace exam3 {

/* A smart appliance is the parent interface for all smart devices. These are
 * devices which can be accessed remotely. The parent is an abstract class with
 * one virtual destructor and three pure virtual methods.
 */
class SmartAppliance {
 public:
  virtual ~SmartAppliance() {}

  virtual const std::string Activate() = 0;
  virtual const std::string Deactivate() = 0;

  virtual const std::string Set(unsigned int setting) = 0;
};

/* A SmartLight interface extends the SmartAppliance. A light is off until it
 * is turned on.
 *
 *  Activate: (1) activates light and returns "Light activated" if light is
 *                deactivated,
 *            (2) returns "Light active" if light is already activated
 *  Deactivate: (1) does nothing and returns the empty string if light is
 *                  already deactivated,
 *              (2) turns off, deactivates light, and returns
                    "Light deactivated" if light is active
 *  Set: (1) does nothing and returns empty string if light is deactivated
 *       (2) if setting is > 0 and light is off, turns light on and returns
 *           "light set from off to on"
 *       (3) if setting is > 0 and light is on, does nothing and returns
 *           "light set on"
 *       (4) if setting is 0 and light is off, does nothing and returns
 *           "light set off"
 *       (5) if setting is 0 and light is on, turns off light and returns
 *         "light set from on to off"
 */
class SmartLight : public SmartAppliance {
 public:
  SmartLight();

  const std::string Activate();

  const std::string Deactivate();

  const std::string Set(unsigned int setting);

 private:
  unsigned int toggle_;
  bool active;
};


/* A SmartThermostat interface extends the SmartAppliance. A thermostat has "no
 * temperature" until it is set. You may represent this however you choose.
 *
 * A thermostat receives it setting as a value in [0, 100]. A thermostat has a
 * temperature range between 40 and 100 degrees Fahrenheight---a range of 60
 * degrees. Use the 0 to 100 as the percent of the range to set the
 * temperature, i.e. setting 50 => 70, setting 0 => 40, setting 100 => 100,
 * etc. You should round correctly.
 *
 *  Activate: (1) activates thermostat and returns "Thermostat activated" if
 *                thermostat is deactivated,
 *            (2) returns "Thermostat active" if thermostat is already
 *                activated
 *  Deactivate: (1) does nothing and returns the empty string if thermostat is
 *                  already deactivated,
 *              (2) turns off, deactivates thermostat, and returns
                    "Thermostat deactivated" if thermostat is active
 *  Set: (1) does nothing and returns empty string if thermostat is deactivated
 *       (2) if setting is different from current setting or does not have a
 *           current setting, changes setting and returns
 *           "thermostat set from <previous setting> to <new setting>"
 *       (3) if setting is same as current setting, does nothing and returns
 *           "thermostat set to <previous setting>"
 */
class SmartThermostat : public SmartAppliance {
 public:
  SmartThermostat();

  const std::string Activate();

  const std::string Deactivate();

  const std::string Set(unsigned int setting);

 private:
  unsigned int toggle_;
  unsigned int temp_;
  unsigned int temp_temp_;
  bool active;
};

}  // namespace exam3

#endif  // NOLINT
