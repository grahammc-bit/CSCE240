CC = g++  # use g++ compiler

FLAGS = -std=c++17  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files


test_parse_scores : test_parse_scores.cc parse_scores.o
	$(LINK) $@ $^

parse_scores.o : parse_scores.cc parse_scores.h
	$(COMPILE) $<

clean:
	rm -f parse_scores.o test_parse_scores
