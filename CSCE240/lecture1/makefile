# Make a compiler variable, named CC
CC = g++

# Make a compiler variable for C++ 17 standard flag named FLAGS
FLAGS = -std=c++17
# Append the "all warnings" flag to variable
FLAGS += -Wall

# Create LINK variable to compile, assemble, link, and name
LINK = $(CC) $(FLAGS) -o

# Create variable COMPILE to compile, assemble, but not link
COMPILE = $(CC) $(FLAGS) -c

# cereal_oz_ton rule
#	Dependencies: cereal_oz_to_ton.cc
#   Command: LINK
#   Executable file name: left side reference, $@
#   Input file(s): right side reference, $^
cereal_oz_ton : cereal_oz_ton.cc
	g++ -std=c++11 -Wall -o cereal_oz_ton cereal_oz_ton.cc

# calc_back_pay rule
#	Dependencies: calc_back_pay.cc
#   Command: LINK
#   Executable file name: left side reference, $@
#   Input file(s): right side reference, $^
calc_back_pay : calc_back_pay.cc
	$(LINK) $@ $^

# calc_sqr_root rule
#	Dependencies: calc_sqr_root.cc
#   Command: LINK
#   Executable file name: left side reference, $@
#   Input file(s): right side reference, $^
calc_sqr_root : calc_sqr_root.cc
	$(LINK) $@ $^


# calc_caff_death rule
#	Dependencies: calc_caff_death.cc
#   Command: LINK
#   Executable file name: left side reference, $@
#   Input file(s): right side reference, $^


# Create a rule to clean up object and executable files.
# Dependencies: none
#   Command: rm (make rm silent)
#   Files: prob*
clean :
	rm -f cereal_oz_ton calc_back_pay calc_sqr_root calc_caff_death
