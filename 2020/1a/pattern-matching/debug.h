#ifndef DEBUG_H
#define DEBUG_H

#define quit cerr.flush();cout.flush();exit(0)

template<typename T>
void db(T& x) {
    cerr << x << endl;
}

template<typename T, typename U>
void db(T& x, U& y) {
    cerr << x << " " << y << endl;
}

template<typename T, typename U, typename V>
void db(T& x, U& y, V& z) {
    cerr << x << " " << y << " " << z << endl;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
    for(T& el: vec) {
        os << el;
        os << " ";
    }
    return os;
}

#endif