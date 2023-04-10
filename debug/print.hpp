//
//  print.hpp
//  ATC
//
//  Created by yuki on 2022/04/17.
//

#ifndef print_h
#define print_h

#define debug(...) print(#__VA_ARGS__, "=", __VA_ARGS__)
#define ptype(T) print(demangle(typeid(T).name()))

#include "desc.hpp"

template<class T> void describe(T v) {
    ss s; desc(s, v); cout << s.str();
}
template<class T> void print(T v) {
    describe(v); cout << endl;
}

template<class Head, class... Tail> void print(Head head, Tail... tail) {
    describe(head); cout << " "; print(tail...);
}

#ifdef should_not_be_define

template<class H, class... T> void print(H h, T... t) { cout << h << ' '; print(t...); }

#endif



#endif /* print_h */

