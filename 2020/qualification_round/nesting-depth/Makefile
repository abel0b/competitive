all: solve

solve: main.cpp
	$(CXX) -march=native -g -O0 $^ -o $@

test: solve
	@if cat input | ./solve | cmp -s - output; then\
		echo "\e[32mAll tests passed successfully\e[0m";\
	else\
		echo "\e[32mExpected:\e[0m";\
		cat output;\
		echo "\e[31mActual:\e[0m";\
		cat input | ./solve;\
	fi

.PHONY: all test