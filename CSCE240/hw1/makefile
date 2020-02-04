CC = g++  # use g++ compiler

FLAGS = -std=c++17  # compile with C++ 17 standard
FLAGS += -Wall      # compile with all warnings

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files

test0 : binary_converter
	python3 test_binary_converter.py 0
test1 : binary_converter
	python3 test_binary_converter.py 1
test2 : binary_converter
	python3 test_binary_converter.py 2
test3 : binary_converter
	python3 test_binary_converter.py 3
test4 : binary_converter
	python3 test_binary_converter.py 4

test_all : test0 test1 test2 test3 test4
	@echo "All Tests Ran"

binary_converter : binary_converter.cc
	$(LINK) $@ $^ 

clean:
	rm -f binary_converter
