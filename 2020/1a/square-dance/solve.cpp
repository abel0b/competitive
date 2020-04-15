// 2020 @abel0b

#include <bits/stdc++.h>

#ifdef DEBUG
#include "debug.h"
#else
#define check(...) 1337
#define debug(...) 1337
#endif

using namespace std;

template<typename T>
using vec = vector<T>;
using pii = pair<int,int>;

#define fi first
#define se second

struct blem {
    int case_num;

    // Problem
    int r, c;
    vec<vec<int>> skl;

    // Solution
    long long int interest = 0;

    blem(int case_num, istream& is): case_num(case_num) {
        is >> r >> c;
        skl = vec<vec<int>>(r,vec<int>(c,-1));

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                cin >> skl[i][j];
            }
        }
    }

    void solve() {
        vec<vec<int>> up(r, vec<int>(c, -1));
        vec<vec<int>> down(r, vec<int>(c, -1));
        vec<vec<int>> left(r, vec<int>(c, -1));
        vec<vec<int>> right(r, vec<int>(c, -1));
        vec<vec<int>> end(r, vec<int>(c, -1));
        vec<pii> todo;

        long long int rdskl = 0;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                rdskl += skl[i][j];
                todo.emplace_back(i,j);
                if (i>0) {
                    up[i][j] = i-1;
                }
                if (i+1<r) {
                    down[i][j] = i+1;
                }
                if (j>0) {
                    left[i][j] = j-1;
                }
                if (j+1<c) {
                    right[i][j] = j+1;
                }
            }
        }

        int rd = 1;
        while(true) {
            debug("round", rd);
            debug("todo", todo);
            interest += rdskl;
            vec<pii> dead;

            bool done = true;
            for(pii pt: todo) {
                int i = pt.first;
                int j = pt.second;
                if (end[i][j] == rd) continue;
                vec<pii> nei;
                if(up[i][j] != -1) nei.emplace_back(up[i][j],j);
                if(down[i][j] != -1) nei.emplace_back(down[i][j],j);
                if(left[i][j] != -1) nei.emplace_back(i,left[i][j]);
                if(right[i][j] != -1) nei.emplace_back(i,right[i][j]);
                debug(pt);
                debug("myneinei", nei);
                if (nei.size()) {
                    int lim = 0;
                    for(auto ne: nei) {
                        lim += skl[ne.first][ne.second];
                    }
                    if (skl[i][j] * (int)nei.size() < lim) {
                        done = false;
                        debug("idie", pt);
                        dead.push_back(pt);
                        end[i][j] = rd;
                        rdskl -= skl[i][j];
                    }
                }
            }

            if (done) break;
            todo.clear();

            for(auto dp: dead) {
                int upn = up[dp.fi][dp.se];
                int don = down[dp.fi][dp.se];
                int len = left[dp.fi][dp.se];
                int rin = right[dp.fi][dp.se];
                if (upn != -1) {
                    down[upn][dp.se] = down[dp.fi][dp.se];
                    pii nw(upn,dp.se);
                    if (end[nw.fi][nw.se] == -1) {
                        todo.push_back(nw);
                    }
                }
                if (don != -1) {
                    up[don][dp.se] = up[dp.fi][dp.se];
                    pii nw(don,dp.se);
                    if (end[nw.fi][nw.se] == -1) {
                        todo.push_back(nw);
                    }
                }
                if (len != -1) {
                    right[dp.fi][len] = right[dp.fi][dp.se];
                    pii nw(dp.fi,len);
                    if (end[nw.fi][nw.se] == -1) {
                        todo.push_back(nw);
                    }
                }
                if (rin != -1) {
                    left[dp.fi][rin] = left[dp.fi][dp.se];
                    pii nw(dp.fi,rin);
                    if (end[nw.fi][nw.se] == -1) {
                        todo.push_back(nw);
                    }
                }
            }
            rd++;
        }
    }

    void write(ostream& os) {
        os << "Case #" << case_num << ": " << interest << "\n";
    }
};

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cerr.tie(nullptr);
    
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
