// 2020 @abel0b

#ifndef NOSYSH
#include <bits/stdc++.h>
#endif

#ifdef DEBUG
#include "debug.h"
#else
#define chk(x) do {} while(0)
#define db(...) do {} while(0)
#endif

using namespace std;

char nl = '\n';

typedef pair<int,int> pii;

struct blem {
    int n;
    bool solve(int tc);
    friend istream& operator>>(istream& is, blem& pb);
};

bool pok(map<pii,bool> visited, vector<pii>& pth, pii& p) {
    return pth.size() <= 501 && visited.find(p) == visited.end() && p.first > 0 && p.second > 0 && p.second <= p.first;
}

void pascal(map<pii,int>& pasc, pii p) {
    if (pasc.find(p) == pasc.end()) {
        if (p.second == 1 || p.first == p.second) {
            pasc[p] = 1;
        }
        else {
            pascal(pasc, pii(p.first-1,p.second-1));
            pascal(pasc, pii(p.first-1,p.second));
            pasc[p] = pasc.at(pii(p.first-1,p.second-1)) + pasc.at(pii(p.first-1,p.second));
        }
    }
}

bool blem::solve(int tc) {
    map<pii,int> pasc;

    vector<pii> stack;
    stack.push_back(pii(1,1));

    vector<int> vals;
    vals.push_back(1);

    pascal(pasc, pii(1,1));
    assert(pasc[pii(1,1)] = 1);
    
    vector<vector<pii>> pths;
    pths.push_back(vector<pii>(1,pii(1,1)));

    vector<map<pii,bool>> visited;
    map<pii,bool> vis;
    vis[pii(1,1)] = true;
    visited.push_back(vis);

    pascal(pasc, pii(2,1));
    pascal(pasc, pii(2,2));
    pascal(pasc, pii(3,2));

    vector<pii> pth;
    int val;

    bool ok = false;
    while(!ok) {
        pii p = stack.back();
        stack.pop_back();

        pth = pths.back();
        pths.pop_back();

        val = vals.back();
        vals.pop_back();

        vis = visited.back();
        visited.pop_back();
        
        if (val == n) {
            ok = true;
        }
        else if (val < n) {
            vector<pii> nei;
            pii tmp;
            tmp = pii(p.first-1,p.second-1);
            if (pok(vis, pth, tmp)) nei.push_back(tmp);

            tmp = pii(p.first-1,p.second);
            if (pok(vis, pth, tmp)) nei.push_back(tmp);

            tmp = pii(p.first,p.second-1);
            if (pok(vis, pth, tmp)) nei.push_back(tmp);

            tmp = pii(p.first,p.second+1);
            if (pok(vis, pth, tmp)) nei.push_back(tmp);

            tmp = pii(p.first+1,p.second);
            if (pok(vis, pth, tmp)) nei.push_back(tmp);

            tmp = pii(p.first+1,p.second+1);
            if (pok(vis, pth, tmp)) nei.push_back(tmp);

            for (pii ne: nei) pascal(pasc, ne);

            sort(nei.begin(), nei.end(), [&pasc](const pii& n1, const pii n2) {
                return pasc.at(n1) < pasc.at(n2);
            });

            for (pii ne: nei) {
                stack.push_back(ne);
                vector<pii> ptn(pth);
                ptn.push_back(ne);
                pths.push_back(ptn);
                vals.push_back(val + pasc[ne]);
                map<pii,bool> visn(vis);
                visn[ne] = true;
                visited.push_back(visn);
            }
        }
    }

    cout << "Case #" << tc << ":" << nl;

    int sum = 0;
    for (pii pt: pth) {
        sum += pasc.at(pt);
        cout << pt.first << " " << pt.second << nl;
    }

    return true;
}

istream& operator>>(istream& is, blem& pb) {
    is >> pb.n;
    return is;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int ntests;
    cin >> ntests;

    for(int tc=1; tc<=ntests; ++tc) {
        blem pb;
        cin >> pb;
        pb.solve(tc);
    }

    return 0;       
}