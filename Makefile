initials = RL
execs = output/string_01 output/tests_string

all: $(execs)
.PHONY: all

clean:
	rm -r output

run: output/string_01
	./output/string_01

run_tests: output/tests_string
	./output/tests_string

output/% : %.cc
	mkdir -p $(@D)
	g++ -g -std=c++11 $< -o $@

string_01 :	string_01 string_01.h
tests_string : 	tests_string.cc string_01.h