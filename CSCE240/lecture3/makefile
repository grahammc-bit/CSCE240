# Make a compiler variable, named CC
CC = g++

# Make a compiler variable for C++ 11 standard flag named FLAGS
FLAGS = -std=c++11
# Append the "all warnings" flag to variable
FLAGS += -Wall

# Create LINK variable to compile, assemble, link, and name
LINK = $(CC) $(FLAGS) -o

# Create variable COMPILE to compile, assemble, but not link
COMPILE = $(CC) $(FLAGS) -c

# prob1 rule
#	Dependencies: calc_wind_chill.cc
#   Command: LINK
#   Executable file name: left side reference, $@
#   Input file(s): right side reference, $^
prob1 : calc_wind_chill.cc
	$(LINK) $@ $^

# prob2 rule
#	Dependencies: calc_sqrt.cc
#   Command: LINK
#   Executable file name: left side reference, $@
#   Input file(s): right side reference, $^
prob2 : calc_sqrt.cc
	$(LINK) $@ $^

# prob3 rule
#	Dependencies: ninety_nine.cc
#   Command: LINK
#   Executable file name: left side reference, $@
#   Input file(s): right side reference, $^
prob3 : ninety_nine.cc
	$(LINK) $@ $^

# Create a rule to make all problems at onces.
#   Dependencies: prob1 ~ prob3

# Create a rule to clean up object and executable files.
#   Dependencies: none
#   Command: rm (make rm silent)
#   Arg: prob*
clean :
	@rm prob*
