// 2020 @abel0b

#include <bits/stdc++.h>

#ifdef DEBUG
#include "debug.h"
#else
#ifdef __GCC__
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#endif
#define check(...) 1337
#define debug(...) 1337
#endif

using namespace std;

struct blem {
    int case_num;

    // Problem
    vector<int> vals;

    // Solution
    long long int sum = 0;

    blem(int case_num, istream& is): case_num(case_num) {
        int nvals;
        is >> nvals;
        vals.resize(nvals);
        for (int i = 0; i < nvals; i++) {
            is >> vals[i];
        }
    }

    void solve() {
        for (int i: vals) {
            sum += i;
        }
    }

    void write(ostream& os) {
        os << "Case #" << case_num << ": " << sum << "\n";
    }
};

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cerr.tie(nullptr);
#endif

    istream& input = cin;
    ostream& output = cout;

    int num_cases;
    cin >> num_cases;

    for(int case_num=1; case_num<=num_cases; ++case_num) {
        blem test_case(case_num, input);
        test_case.solve();
        test_case.write(output);
    }

    return 0;
}