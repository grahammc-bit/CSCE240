# Make a compiler variable, named CC
CC = g++

# Make a compiler variable for C++ 11 standard flag named FLAGS
FLAGS = -std=c++17
# Append the "all warnings" flag to variable
FLAGS += -Wall

# Create LINK variable to compile, assemble, link, and name
LINK = $(CC) $(FLAGS) -o

# Create variable COMPILE to compile, assemble, but not link
COMPILE = $(CC) $(FLAGS) -c

# calc_inflation rule
#	Dependencies: calc_inflation.cc
#   Command: LINK
#   Executable file name: left side reference, $@
#   Input file(s): right side reference, $^
calc_inflation : calc_inflation.cc
	$(LINK) $@ $^

# calc_prime rule
#	Dependencies: calc_prime.cc
#   Command: LINK
#   Executable file name: left side reference, $@
#   Input file(s): right side reference, $^
calc_prime : calc_prime.cc
	$(LINK) $@ $^

# calc_sqrt rule
#	Dependencies: calc_sqrt.cc
#   Command: LINK
#   Executable file name: left side reference, $@
#   Input file(s): right side reference, $^
calc_sqrt : calc_sqrt.cc
	$(LINK) $@ $^

# calc_avg rule
#	Dependencies: calc_avg.cc
#   Command: LINK
#   Executable file name: left side reference, $@
#   Input file(s): right side reference, $^
calc_avg : calc_avg.cc
	$(LINK) $@ $^

# parse_file rule
#	Dependencies: calc_avg.cc
#   Command: LINK
#   Executable file name: left side reference, $@
#   Input file(s): right side reference, $^
parse_file : parse_file.cc
	$(LINK) $@ $^

# Create a rule to make all problems at onces.
#   Dependencies: calc_inflation ~ parse_file

# Create a rule to clean up object and executable files.
#   Dependencies: none
#   Command: rm (make rm silent)
#   Arg: prob*
clean :
	rm -f calc_inflation calc_prime calc_sqrt calc_avg parse_file
