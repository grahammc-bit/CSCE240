CC = g++  # use g++ compiler

FLAGS = -std=c++17  # compile with C++ 17 standard
FLAGS += -Wall      # compile with all warnings
FLAGS += -I .       # compile with project directory on #include system path
FLAGS += -g

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable
COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files


# PROBLEM: functional_array
#
test_functional_array : bin/functional_array.o bin/test_functional_array.o
	$(LINK) $@ $^

test_functional_array_memory : test_functional_array
	valgrind --leak-check=full --error-exitcode=1 ./test_functional_array 1
	valgrind --leak-check=full --error-exitcode=1 ./test_functional_array 3
	@echo ALL MEMORY TESTS PASSED

bin/test_functional_array.o : src/test_functional_array.cc \
                              inc/test_functional_array.h \
                              inc/functional_array.h
	$(COMPILE) -o $@ $<

bin/functional_array.o : src/functional_array.cc inc/functional_array.h
	$(COMPILE) -o $@ $<


# PROBLEM: tight_vector
#
test_tight_vector : bin/tight_vector.o bin/test_tight_vector.o
	$(LINK) $@ $^

test_tight_vector_memory : test_tight_vector
	valgrind --leak-check=full --error-exitcode=1 ./test_tight_vector 1
	valgrind --leak-check=full --error-exitcode=1 ./test_tight_vector 3
	@echo ALL TESTS PASSED

bin/test_tight_vector.o : src/test_tight_vector.cc \
                          inc/test_tight_vector.h \
                          inc/tight_vector.h
	$(COMPILE) -o $@ $<

bin/tight_vector.o : src/tight_vector.cc inc/tight_vector.h
	$(COMPILE) -o $@ $<


# PROBLEM: char_matrix
#
test_char_matrix : bin/char_matrix.o bin/test_char_matrix.o
	$(LINK) $@ $^

test_char_matrix_memory : test_char_matrix
	valgrind --leak-check=full --error-exitcode=1 ./test_char_matrix 0
	valgrind --leak-check=full --error-exitcode=1 ./test_char_matrix 1
	valgrind --leak-check=full --error-exitcode=1 ./test_char_matrix 2
	@echo ALL TESTS PASSED

bin/test_char_matrix.o : src/test_char_matrix.cc \
                         inc/test_char_matrix.h \
                         inc/char_matrix.h
	$(COMPILE) -o $@ $<

bin/char_matrix.o : src/char_matrix.cc inc/char_matrix.h
	$(COMPILE) -o $@ $<


# PROBLEM: time_span
#
test_time_span : bin/time_span.o bin/test_time_span.o
	$(LINK) $@ $^

bin/test_time_span.o : src/test_time_span.cc \
                         inc/test_time_span.h \
                         inc/time_span.h
	$(COMPILE) -o $@ $<

bin/time_span.o : src/time_span.cc inc/time_span.h
	$(COMPILE) -o $@ $<


# UTILITY: cleans and zips this exam
archive : clean
	zip -r ../exam2_submission.zip ../exam2


# UTILITY: removes intermediary files and executables
clean:
	rm -f bin/* test_functional_array test_tight_vector test_char_matrix test_time_span
