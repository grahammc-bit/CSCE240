// Copyright 2020 Matthew Graham
#include <inc/smart_appliance.h>

using std::string;

namespace exam3 {

// Start SmartLight
SmartLight::SmartLight() : toggle_(0), active(false) { /* empty */ }

const string SmartLight::Activate() {
  if (toggle_ == 0) {
    toggle_ = 1;
    active = true;
    return "Light activated";
  } else if (toggle_ == 1) {
    return "Light active";
  }
  return "";
}

const string SmartLight::Deactivate() {
  if (toggle_ == 0) {
    return "";
  } else if (toggle_ == 1) {
    toggle_ = 0;
    active = false;
    return "Light deactivated";
  }
  return "";
}

const string SmartLight::Set(unsigned int setting) {
  if (active == false)
    return "";
  if (setting > 0 && toggle_ == 0) {
    toggle_ = 1;
    return "Light set from off to on";
  }
  if (setting > 0 && toggle_ == 1) {
    return "Light set on";
  }
  if (setting == 0 && toggle_ == 0) {
    return "Light set off";
  }
  if (setting == 0 && toggle_ == 1) {
    toggle_ = 0;
    return "Light set from on to off";
  }
  return "";
}
// End SmartLight


// Start SmartThermostat
SmartThermostat::SmartThermostat() : toggle_(0), temp_(0),
                                     temp_temp_(0) { /* empty */ }

const string SmartThermostat::Activate() {
  if (toggle_ == 0) {
    toggle_ = 1;
    active = true;
    return "Thermostat activated";
  } else if (toggle_ == 1) {
    return "Thermostat active";
  }
  return "";
}

const string SmartThermostat::Deactivate() {
  if (toggle_ == 0) {
    return "";
  } else if (toggle_ == 1) {
    toggle_ = 0;
    active = false;
    return "Thermostat deactivated";
  }
  return "";
}

const string SmartThermostat::Set(unsigned int setting) {
  stringstream ss;
  if (active != false) {
    if (temp_ != setting || temp_ == 0) {
      temp_temp_ = temp_;
      temp_ = ((setting * 0.01) * 60) + 40;
      ss << "Thermostat set from " << temp_temp_ << " to " << temp_;
      return ss.str();
    }
    if (temp_ == setting) {
      ss << "Thermostat set to " << temp_;
      return ss.str();
    }
  }
  return "";
}
// End SmartThermoStat

}  // namespace exam3
