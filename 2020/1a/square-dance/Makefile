CXX = g++
CXXFLAGS = -std=c++14 -pthread

all: release

release: CXXFLAGS += -O3
release: solve

debug: CXXFLAGS += -DDEBUG -O0 -g -Wall -Wextra
debug: solve

strict: CXXFLAGS += -DDEBUG -O0 -g -Wall -Wextra -Wfatal-errors -Werror
strict: solve

solve: solve.cpp debug.h
	$(CXX) $(CXXFLAGS) solve.cpp -o $@

test: $(subst ./,test-,$(basename $(shell find . -name *.in)))

test-%: debug %.in %.out
	@if cat $*.in | ./solve | cmp -s - $*.out; then\
		echo "\e[32mPASS\e[0m $*";\
	else\
		echo "\e[31mFAIL\e[0m $*";\
		echo "\e[32mExpected:\e[0m";\
		cat small.out;\
		echo "\e[31mActual:\e[0m";\
		cat small.in | ./solve;\
	fi

clean:
	rm -f solve

.PHONY: all release debug strict test% clean
