CC = g++  # use g++ compiler

FLAGS = -std=c++17  # compile with C++ 17 standard
FLAGS += -Wall      # compile with all warnings
FLAGS += -g         # compile with gdb instrumentation
FLAGS += -I .       # compile with project directory on #include system path

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable
COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files


test_item : bin/test_item.o bin/item.o bin/tax.o
	$(LINK) $@ $^
test_item_memory : test_item
	valgrind --leak-check=full --error-exitcode=1 ./test_item 0
	valgrind --leak-check=full --error-exitcode=1 ./test_item 1
	valgrind --leak-check=full --error-exitcode=1 ./test_item 2
	@echo No leaks found

bin/test_item.o : test/src/test_item.cc test/inc/test_item.h inc/item.h
	$(COMPILE) -o $@ $<

bin/item.o : src/item.cc inc/item.h inc/tax.h
	cpplint --root=./ $^
	$(COMPILE) -o $@ $<


test_tax : bin/test_tax.o bin/tax.o
	$(LINK) $@ $^

bin/test_tax.o : test/src/test_tax.cc test/inc/test_tax.h inc/tax.h
	$(COMPILE) -o $@ $<

bin/tax.o : src/tax.cc inc/tax.h
	cpplint --root=./ $^
	$(COMPILE) -o $@ $<

clean:
	rm -f bin/* test_item test_tax
