/* Copyright 2020 CSCE240 Exam 3
 */
#include <test/inc/smart_appliance.h>
using exam3::SmartAppliance;
using exam3::SmartLight;
using exam3::SmartThermostat;
using std::cout;
using std::endl;
using std::string;


int main(int argc, char* argv[]) {
  cout << " Testing SmartLight" << endl;
  SmartAppliance *appliance = new SmartLight();
  TestSmartApplianceActivate(0, appliance, "Light");
  delete appliance;
  appliance = new SmartLight();
  TestSmartApplianceActivate(1, appliance, "Light");
  delete appliance;
  appliance = new SmartLight();
  TestSmartApplianceDeactivate(0, appliance, "Light");
  delete appliance;
  appliance = new SmartLight();
  TestSmartApplianceDeactivate(1, appliance, "Light");
  delete appliance;
  for (unsigned int i = 1; i < 6; ++i) {
    appliance = new SmartLight();
    TestSmartLightSet(i, appliance);
    delete appliance;
  }

  cout << " Testing SmartThermostat" << endl;
  appliance = new SmartThermostat;
  TestSmartApplianceActivate(0, appliance, "Thermostat");
  delete appliance;
  appliance = new SmartThermostat;
  TestSmartApplianceActivate(1, appliance, "Thermostat");
  delete appliance;
  appliance = new SmartThermostat;
  TestSmartApplianceDeactivate(1, appliance, "Thermostat");
  delete appliance;
  appliance = new SmartThermostat;
  TestSmartApplianceDeactivate(1, appliance, "Thermostat");
  delete appliance;
  for (unsigned int i = 1; i < 4; ++i) {
    appliance = new SmartThermostat;
    TestSmartThermostatSet(i, appliance);
    delete appliance;
  }

  return 0;
}

                           
bool TestSmartApplianceActivate(unsigned int test,
                                SmartAppliance* appliance,
                                const string& name) {
  cout << "  Smart" << name << "::Activate : ";
  if (test == 1) {
    if (appliance->Activate() == name +  " activated") {
      cout << "PASSED" << endl;
      return true;
    } else {
      cout << "FAILED" << endl;
      return false;
    }
  } else {  // test 2
    appliance->Activate();
    if (appliance->Activate() == name +  " active") {
      cout << "PASSED" << endl;
      return true;
    } else {
      cout << "FAILED" << endl;
      return false;
    }
  }
}

bool TestSmartApplianceDeactivate(unsigned int test,
                                  SmartAppliance* appliance,
                                  const string& name) {
  cout << "  Smart" << name << "::Deactivate : ";
  if (test == 1) {
    if (appliance->Deactivate() == "") {
      cout << "PASSED" << endl;
      return true;
    } else {
      cout << "FAILED" << endl;
      return false;
    }
  } else {  // test 2
    appliance->Activate();
    if (appliance->Deactivate() == name +  " deactivated") {
      cout << "PASSED" << endl;
      return true;
    } else {
      cout << "FAILED" << endl;
      return false;
    }
  }
}

bool TestSmartLightSet(unsigned int test, exam3::SmartAppliance* appliance) {
  if (test == 1)
    return (TestSmartApplianceSet(test, 0, 0, "", appliance, "Light"));
  else if (test == 2)
    return (TestSmartApplianceSet(
        test, 0, 1, "Light set from off to on", appliance, "Light"));
  else if (test == 3)
    return (TestSmartApplianceSet(
        test, 1, 1, "Light set on", appliance, "Light"));
  else if (test == 4)
    return (TestSmartApplianceSet(
        test, 0, 0, "Light set off", appliance, "Light"));
  else  // test == 5
    return (TestSmartApplianceSet(
        test, 1, 0, "Light set from on to off", appliance, "Light"));
}

bool TestSmartThermostatSet(unsigned int test,
                            exam3::SmartAppliance* appliance) {
  if (test == 1)
    return (TestSmartApplianceSet(test, 0, 0, "", appliance, "Thermostat"));
  else if (test == 2)
    return (TestSmartApplianceSet(
        test, 0, 75, "Thermostat set from 40 to 85", appliance, "Thermostat"));
  else if (test == 3)
    return (TestSmartApplianceSet(
        test, 25, 25, "Thermostat set to 55", appliance, "Thermostat"));
}

bool TestSmartApplianceSet(unsigned int test,
                           unsigned int start_setting,
                           unsigned int test_setting,
                           const string& expected,
                           exam3::SmartAppliance* appliance,
                           const string& name) {
  cout << "  Smart" << name << "::Set : ";
  if (test == 1) {
    if (appliance->Set(0) == "") {
      cout << "PASSED" << endl;
      return true;
    } else {
      cout << "FAILED" << endl;
      return false;
    }
  } else  {  // test 2 ~ 5
    appliance->Activate();
    appliance->Set(start_setting);
    if (appliance->Set(test_setting) == expected) {
      cout << "PASSED" << endl;
      return true;
    } else {
      cout << "FAILED" << endl;
      return false;
    }
  }
}
