execs = string_01
tests = tests_string

all: $(execs) $(tests)
.PHONY: all

clean:
	rm $(execs)

test: $(execs) $(tests)
	@$(foreach test, $(tests), echo "RUNNING: $(test)" && ./$(test))

check:
	cppcheck --inline-suppr --enable=all --inconclusive --library=posix --suppress=missingIncludeSystem .

% : %.cc
	g++ -g -fstack-protector-strong -fcf-protection=full -fstack-clash-protection -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion -Wcast-qual -Wformat=2 -Wundef -Wshadow -Wcast-align -Wunused -Wnull-dereference -Wdouble-promotion -Wimplicit-fallthrough -Wextra-semi -Woverloaded-virtual -Wnon-virtual-dtor -Wold-style-cast -std=c++17 $< -o $@

string_01 : string_01.cc string_01.h
tests_string : tests_string.cc string_01.h
