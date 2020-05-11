CC = g++
FLAGS = -std=c++17
FLAGS += -Wall

LINK = $(CC) $(FLAGS) -o

fact : fact.cc 
				$(LINK) $@ $^

fact_arg : fact_arg.cc
				$(LINK) $@ $^

switch : switch.cc
				$(LINK) $@ $^

libs : libs.cc
				$(LINK) $@ $^

intro : intro.cc intro.h
				$(LINK) $@ $^

file : file.cc file.h
				$(LINK) $@ $^

clean:
				@rm fact fact_arg switch intro libs
				@echo Removing bin files