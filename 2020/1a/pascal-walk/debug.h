#ifndef DEBUG_H
#define DEBUG_H

#include <bits/stdc++.h>

using namespace std;

#define dout cout << __FILE__ << "(" << __LINE__ << ")"
#define quit cerr.flush();cout.flush();exit(0)
#define chk(x) cerr.flush();cout.flush();assert(x)

template<typename T>
void db(T& t1) {
    dout << t1 << endl;
}

template<typename T1, typename T2>
void db(T1& t1, T2& t2) {
    dout << t1 << " " << t2 << endl;
}

template<typename T1, typename T2, typename T3>
void db(T1& t1, T2& t2, T3& t3) {
    dout << t1 << " " << t2 << " " << t3 << endl;
}

template<typename T1, typename T2, typename T3, typename T4>
void db(T1& t1, T2& t2, T3& t3, T4& t4) {
    dout << t1 << " " << t2 << " " << t3 << " " << t4 << endl;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
    os << "vector[";
    for(T& el: vec) {
        os << el;
        os << " ";
    }
    os << "]";
    return os;
}

template<typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U>& p) {
    os << "pair(" << p.first << " " << p.second << ")";
    return os;
}

#endif