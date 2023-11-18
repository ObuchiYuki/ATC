//
//  desc.hpp
//  UTP
//
//  Created by yuki on 2022/06/12.
//

#include "demangle.hpp"

#define SFINAE(name, check) template<class T> struct name {\
    template<class C> static auto test(C*) -> decltype(check, true_type());\
    template<class C> static auto test(...) -> false_type;\
    static constexpr bool value = is_same<decltype(name::test<T>(0)), true_type>::value;\
}\

SFINAE(has_desc, declval<C>().desc(declval<ss&>()));
SFINAE(has_sout, cout << declval<C>());

template<class T> auto desc(ss &s, T v) -> typename enable_if<has_desc<T>::value and has_sout<T>::value, void>::type {
    v.desc(s);
}
template<class T> auto desc(ss &s, T v) -> typename enable_if<!has_desc<T>::value and has_sout<T>::value, void>::type {
    s << v;
}
template<class T> auto desc(ss &s, T v) -> typename enable_if<has_desc<T>::value and !has_sout<T>::value, void>::type {
    v.desc(s);
}
template<class T> auto desc(ss &s, T v) -> typename enable_if<!has_desc<T>::value and !has_sout<T>::value, void>::type {
    s << "<" << simple_demangle(typeid(v).name()) << " with " << sizeof(T) << " bytes" << ">";
}

template<class T> void desc(ss &s, vector<T> v);
template<class T, class U> void desc(ss &s, pair<T, U> v);
template<class T, class C> void desc(ss &s, multiset<T, C> v);
template<class T> void desc(ss &s, unordered_set<T> v);
template<class T, class U> void desc(ss &s, map<T, U> v);
template<class T, class U> void desc(ss &s, unordered_map<T, U> v);
template<class T, class C> void desc(ss &s, set<T, C> v);
template<class T> void desc(ss &s, queue<T> v);
template<class T, class C, class P> void desc(ss &s, priority_queue<T, C, P> v);
template<class... A> void desc(ss &s, tuple<A...> v);

void desc(ss &s, bool v) {
    s << (v ? "true" : "false");
}

#ifdef CHAR_AS_INT
void desc(ss &s, char v) {
    s << +v;
}
#endif

void desc(ss &s, string v) {
    s << v;
}
#ifndef PAIR_AS_INIT
template<class T, class U> void desc(ss &s, pair<T, U> v) {
    s << "("; desc(s, v.first); s << ", "; desc(s, v.second); s << ")";
}
#else
template<class T, class U> void desc(ss &s, pair<T, U> v) {
    s << "{"; desc(s, v.first); s << ", "; desc(s, v.second); s << "}";
}
#endif

template<class T> void desc(ss &s, vector<T> v) {
    auto f = true; s << "{ ";
    for(auto t: v) { if (f) f = 0; else s << ", "; desc(s, t); } s << " }";
}
template<class K, class V> void desc(ss &s, map<K, V> v) {
    auto f = true; s << "{ ";
    for(auto t: v) { if (f) f = 0; else s << ", "; desc(s, t.first); s << ": "; desc(s, t.second); } s << " }";
}
template<class T> void desc(ss &s, vector<vector<T>> v) {
    s << "{" << endl; for(auto t: v) { s << "\t"; desc(s, t); s << endl; } s << "}";
}
template<class T> void desc(ss &s, vector<vector<vector<T>>> v) {
    s << "{" << endl;
    for(auto &t1: v) {
        s << "\t{" << endl;
        for(auto &t2: t1) {
            s << "\t\t";
            desc(s, t2);
            s << endl;
        }
        s << "\t}" << endl;
    }
    s << "}";
}

template<class T> void desc(ss &s, vector<vector<vector<vector<T>>>> v) {
    s << "{" << endl;
    for (auto &t1: v) {
        s << "\t{" << endl;
        for (auto &t2: t1) {
            s << "\t\t{" << endl;
            for (auto &t3: t2) {
                s << "\t\t\t";
                desc(s, t3);
                s << endl;
            }
            s << "\t\t}" << endl;
        }
        s << "\t}" << endl;
    }
    s << "}";
}
template<class K, class V> void desc(ss &s, unordered_map<K, V> v) {
    desc(s, map(v.begin(), v.end()));
}
template<class T> void desc(ss &s, unordered_set<T> v) {
    desc(s, vector(v.begin(), v.end()));
}
template<class T, class C> void desc(ss &s, set<T, C> v) {
    desc(s, vector(v.begin(), v.end()));
}
template<class T> void desc(ss &s, unordered_multiset<T> v) {
    desc(s, vector(v.begin(), v.end()));
}
template<class T, class C, class P> void desc(ss &s, priority_queue<T, C, P> v) {
    vector<T> vec; while(v.size()) { vec.push_back(v.top()); v.pop(); }
    desc(s, vec);
}
template<class T, class C> void desc(ss &s, multiset<T, C> v) {
    desc(s, vector(v.begin(), v.end()));
}
template<class T> void desc(ss &s, queue<T> v) {
    vector<T> vec; while(v.size()) { vec.push_back(v.front()); v.pop(); }
    desc(s, vec);
}
template<class T> void desc(ss &s, stack<T> v) {
    vector<T> vec; while(v.size()) { vec.push_back(v.top()); v.pop(); }
    desc(s, vec);
}

#ifdef STRINGS_AS_FIELD
auto desc(ss &s, vector<string> v) {
    for(auto &t: v) { desc(s, t); s << endl; }
}
#endif

#ifdef CHARS_AS_FIELD
auto desc(ss &s, vector<vector<char>> v) {
    for (auto &row: v) {
        for (auto &c: row) cout << c;
        cout << endl;
    }
}
#endif

template<size_t I, class... T>
typename enable_if<I == sizeof...(T), void>::type _desc(ss &s, tuple<T...> t) {}
template<size_t I, class... T>
typename enable_if<I < sizeof...(T), void>::type _desc(ss &s, tuple<T...> t) { if (I) s << ", "; s << get<I>(t); _desc<I+1, T...>(s, t); }

template<class... A> void desc(ss &s, tuple<A...> v) { s << "("; _desc<0>(s, v); s << ")"; }

template<class T> void _concat(ss &s, T h) { desc(s, h); }
template<class H, class... T> void _concat(ss &s, H h, T... t) { desc(s, h); s << ", "; _concat(s, t...); }


template<class H, class... T> void dump(ss &s, T... t) {
    s << simple_demangle(typeid(H).name()) << "("; _concat(s, t...); s << ")";
}
template<class... T> void dump(ss &s, T... t) {
    s << "("; _concat(s, t...); s << ")";
}
