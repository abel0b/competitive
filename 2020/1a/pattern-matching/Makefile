CXXFLAGS = -std=c++14 -pthread
PROBLEM = $$(basename $$(dirname $$(dirname $$(pwd))))/$$(basename $$(dirname $$(pwd)))/$$(basename $$(pwd))

all: release

debug: CXXFLAGS += -DDEBUG -O0 -g
debug: solve

release: CXXFLAGS += -O3 -march=native
release: solve

solve: solve.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

test: debug small.in small.out
	@if cat small.in | ./solve | cmp -s - small.out; then\
		echo "\e[32mPASS\e[0m $(PROBLEM)";\
	else\
		echo "\e[31mFAIL\e[0m $(PROBLEM)";\
		echo "\e[32mExpected:\e[0m";\
		cat small.out;\
		echo "\e[31mActual:\e[0m";\
		cat small.in | ./solve;\
	fi

perf: release
	cat small.in | perf stat ./solve

clean:
	rm -f solve

.PHONY: all release debug test perf clean
