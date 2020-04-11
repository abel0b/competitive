// 2020 Abel Calluaud <abel0b@pm.me>

#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.h"
#endif

typedef vector<string> svec;
typedef vector<int> ivec;

struct blem {
    int npats;
    vector<string> pats;
    bool solve();
    friend istream& operator>>(istream& is, blem& pb);
};

bool blem::solve() {
    string ans;
    string mid;
    bool ok = true;
    svec pref(npats, "");
    svec suf(npats, "");
    int imp = 0;
    int ims = 0;

    for(int i=0; i<npats; i++) {
        for(int j=0; j<pats[i].size(); ++j) {
            if (pats[i][j] == '*') break;
            pref[i].push_back(pats[i][j]);
        }
        if (pref[imp].size()<pref[i].size()) {
            imp = i;
        }

        int jsuf = -1;
        for(int j=pats[i].size()-1; j>=0; --j) {
            if (pats[i][j] == '*') {
                jsuf = j;
                break;
            }
        }
        if (jsuf != -1) {
            suf[i] = pats[i].substr(jsuf+1, pats[i].size());
        }

        if (suf[ims].size()<suf[i].size()) {
            ims = i;
        }
    }

    for(int i=0; i<npats; ++i) {
        string mids =  pats[i].substr(pref[i].size(), pats[i].size()-suf[i].size());
        for(char c: mids) {
            if (c != '*') {
                mid.push_back(c);
            }
        }
    }

    for(int i=0; i<npats; i++) {
        if(pref[imp].substr(0, pref[i].size()) != pref[i]) {
            ok = false; break;
        }
        if(suf[ims].substr(suf[ims].size()-suf[i].size(), suf[ims].size()) != suf[i]) {
            ok = false; break;
        }
    }

    if(ok) {
        ans = pref[imp] + mid + suf[ims];
    }
    else {
        ans = "*";
    }
    
    cout << ans << "\n";
    return true;
}

istream& operator>>(istream& is, blem& pb) {
    is >> pb.npats;
    pb.pats.resize(pb.npats);
    for (int i = 0; i < pb.npats; i++) {
        is >> pb.pats[i];
    }
    return is;
}

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

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