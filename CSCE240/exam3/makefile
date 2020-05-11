CC = g++  # use g++ compiler

FLAGS = -std=c++17  # compile with C++ 17 standard
FLAGS += -Wall      # compile with all warnings
FLAGS += -I .       # compile with project directory on #include system path

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable
COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files


# PROBLEM: Employee Inheritance
#
test-employee: bin/employee.o bin/test-employee.o
	$(LINK) $@ $^

test-employee-style: src/employee.cc inc/employee.h
	cpplint --root=./ $^

bin/test-employee.o : test/src/employee.cc test/inc/employee.h inc/employee.h
	$(COMPILE) -o $@ $<

bin/employee.o : src/employee.cc inc/employee.h
	$(COMPILE) -o $@ $<


# PROBLEM: Smart Appliance
#
test-smart-appliance : bin/smart-appliance.o bin/test-smart-appliance.o
	$(LINK) $@ $^

test-smart-appliance-style: src/smart_appliance.cc inc/smart_appliance.h
	cpplint --root=./ $^

bin/test-smart-appliance.o : test/src/smart_appliance.cc \
                             test/inc/smart_appliance.h \
                             inc/smart_appliance.h
	$(COMPILE) -o $@ $<

bin/smart-appliance.o : src/smart_appliance.cc inc/smart_appliance.h
	$(COMPILE) -o $@ $<


# UTILITY: removes intermediary files and executables
clean:
	@rm -f bin/* test-employee test-smart-appliance
