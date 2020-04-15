#ifndef DEBUG_H
#define DEBUG_H

#include <bits/stdc++.h>

#define yo cout << "YO[" << __FILE__ << ":" << __LINE__ << "]" << std::endl;std::cerr.flush();std::cout.flush();exit(0)
#define check(x) std::cerr.flush();std::cout.flush();std::assert(x)

template<typename Arg, typename... Args>
void print_debug(const char * filename, int line, Arg&& arg, Args&&... args) {
    std::cerr << '[' << filename << ':' << line << "] " << std::forward<Arg>(arg);
    using expander = int[];
    (void)expander{0,(void(std::cerr << " " << std::forward<Args>(args)), 0)...};
    std::cerr << std::endl;
}
#define debug(...) print_debug(static_cast<const char*>(__FILE__), __LINE__, __VA_ARGS__)

template<typename T, typename U>
std::ostream& operator<<(std::ostream& os, std::vector<T,U>& vec) {
    os << "vec[";
    for(auto it = vec.begin(); it != vec.end(); it++) {
        if (it != vec.begin()) {
            os << " ";
        }
        os << *it;
    }
    os << "]";
    return os;
}

template<typename T, typename U>
std::ostream& operator<<(std::ostream& os, std::pair<T, U>& p) {
    os << "pair(" << p.first << " " << p.second << ")";
    return os;
}

template<typename T, typename U>
std::ostream& operator<<(std::ostream& os, std::map<T, U>& mp) {
    os << "map[";
    for(auto it = mp.begin(); it != mp.end(); it++) {
        if (it != mp.begin()) {
            os << " ";
        }
        os << it->first << "=" << it->second;
    }
    os << "]";
    return os;
}

template<typename T,typename U>
std::ostream& operator<<(std::ostream& os, std::unordered_set<T,U>& s) {
    os << "uset[";
    auto it = s.begin();
    os << *it;
    it++;
    for(++it; it != s.end(); it++) {
        if (it != s.begin()) {
            os << " ";
        }
        os << *it;
    }
    os << "]";
    return os;
}

#endif