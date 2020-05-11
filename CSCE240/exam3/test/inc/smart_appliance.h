/* Copyright 2020 CSCE240 Exam 3
 */
#ifndef TEST_INC_SMART_APPLIANCE_H_
#define TEST_INC_SMART_APPLIANCE_H_


#include <inc/smart_appliance.h>

#include <iostream>
#include <string>


bool TestSmartApplianceActivate(unsigned int test,
                                exam3::SmartAppliance* appliance,
                                const std::string& name);

bool TestSmartApplianceDeactivate(unsigned int test,
                                  exam3::SmartAppliance* appliance,
                                  const std::string& name);

bool TestSmartLightSet(unsigned int test, exam3::SmartAppliance* appliance);
bool TestSmartThermostatSet(unsigned int test,
                            exam3::SmartAppliance* appliance);
bool TestSmartApplianceSet(unsigned int test,
                           unsigned int start_setting,
                           unsigned int test_setting,
                           const std::string& expected,
                           exam3::SmartAppliance* appliance,
                           const std::string& name);


#endif  // TEST_INC_SMART_APPLIANCE_H_
