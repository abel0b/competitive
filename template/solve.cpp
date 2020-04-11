// 2020 Abel Calluaud <abel0b@pm.me>

#include <bits/stdc++.h>
using namespace std;

struct blem {
    vector<int> vals;
    bool solve();
    friend istream& operator>>(istream& is, blem& pb);
};

bool blem::solve() {
    int sum = 0;
    for (int i: vals) {
        sum += i;
    }
    cout << sum << "\n";
    return true;
}

istream& operator>>(istream& is, blem& pb) {
    int nvals;
    is >> nvals;
    pb.vals.resize(nvals);
    for (int i = 0; i < nvals; i++) {
        is >> pb.vals[i];
    }
    return is;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int ntests;
    cin >> ntests;

    for(int test=1; test<=ntests; ++test) {
        blem pb;
        cin >> pb;
        std::cout << "Case #" << test << ": ";
        assert(pb.solve());
    }

    return 0;       
}