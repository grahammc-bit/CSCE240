cc = g++  # use g++ compiler

flags = -std=c++17  # compile with C++ 17 standard
flags += -Wall      # compile with all warnings
flags += -g         # produce debugging information
flags += -I .       # add pwd directory to src include path

LINK = $(cc) $(flags) -o  # final linked build to binary executable

COMPILE = $(cc) $(flags) -c  # compilation to intermediary .o files

test: mean-collect mean-calculate median-collect median-calculate
	./mean-collect
	./mean-calculate
	./median-collect
	./median-calculate

test-memory: mean-collect mean-calculate median-collect median-calculate
	valgrind --leak-check=full --error-exitcode=1 ./mean-collect
	valgrind --leak-check=full --error-exitcode=1 ./mean-calculate
	valgrind --leak-check=full --error-exitcode=1 ./median-collect
	valgrind --leak-check=full --error-exitcode=1 ./median-collect
	@echo "Memory Test: PASSED"

test-style: inc/mean.h inc/median.h inc/statistic.h \
            src/mean.cc src/median.cc src/statistic.cc
	cpplint --root=./ $^

mean-collect: bin/mean-collect.o bin/mean.o bin/statistic.o
	$(LINK) $@ $^
bin/mean-collect.o: test/src/mean_collect.cc inc/mean.h inc/statistic.h
	$(COMPILE) $< -o $@

mean-calculate: bin/mean-calculate.o bin/mean.o bin/statistic.o
	$(LINK) $@ $^
bin/mean-calculate.o: test/src/mean_calculate.cc inc/mean.h inc/statistic.h
	$(COMPILE) $< -o $@


median-collect: bin/median-collect.o bin/median.o bin/statistic.o
	$(LINK) $@ $^
bin/median-collect.o: test/src/median_collect.cc inc/median.h inc/statistic.h
	$(COMPILE) $< -o $@

median-calculate: bin/median-calculate.o bin/median.o bin/statistic.o
	$(LINK) $@ $^
bin/median-calculate.o: test/src/median_calculate.cc inc/median.h \
                        inc/statistic.h
	$(COMPILE) $< -o $@

bin/statistic.o: src/statistic.cc inc/statistic.h
	$(COMPILE) $< -o $@

bin/mean.o: src/mean.cc inc/mean.h inc/statistic.h
	$(COMPILE) $< -o $@

bin/median.o: src/median.cc inc/median.h inc/statistic.h
	$(COMPILE) $< -o $@

clean:
	rm -f bin/* mean-* median-*
