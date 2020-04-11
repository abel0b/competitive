#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <numeric>
#include <string>

using namespace std;

struct Problem {
    string digits;
    bool solve();
};

bool Problem::solve() {
    bool solved = true;
  
    string output;
    int pcount = 0;

    for(char const & c: digits) {
        int digit = c - '0';
        if (pcount > digit) {
            while(pcount != digit) {
                output.push_back(')');
                pcount --;
            }
        }
        if (pcount < digit) {
            while(pcount != digit) {
                output.push_back('(');
                pcount ++;
            }
        }
        output.push_back(c);
    }

    while(pcount != 0) {
        output.push_back(')');
        pcount --;
    }
    
    std::cout << output << endl;

    return solved;
}

int main() {
    int test_cases;
    cin >> test_cases;

    for(int test_case=0; test_case<test_cases; ++test_case) {
        Problem problem;
        cin >> problem.digits;
        std::cout << "Case #" << test_case+1 << ": ";
        assert(problem.solve());
    }

    return 0;       
}
