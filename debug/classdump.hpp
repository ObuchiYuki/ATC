//
//  classdump.hpp
//  ATC
//
//  Created by yuki on 2022/06/28.
//

#ifndef classdump_h
#define classdump_h

namespace _classdump {
vector<string> split_param(string const &self) {
    string buffer;
    vector<string> res;
    for (auto c: self) {
        if (c == ',') {
            res.push_back(buffer);
            buffer.clear();
        } else if (c != ' ') {
            buffer.push_back(c);
        }
    }
    res.push_back(buffer);
    return res;
}

template<class T> void concat(ss &s, vector<string> &fields, T h) {
    s << fields[fields.size()-1] << ": "; desc(s, h);
}
template<class H, class... T> void concat(ss &s, vector<string> &fields, H h, T... t) {
    s << fields[fields.size()-sizeof...(T)-1] << ": "; desc(s, h); s << ", "; concat(s, fields, t...);
}

template<class H, class... T> void dump(ss &s, H self, string params, T... t) {
    vector<string> fields = split_param(params);
    s << simple_demangle(typeid(self).name()) << "(";
    concat(s, fields, t...);
    s << ")";
}
}

#define classdump(...) void desc(ss &s) { _classdump::dump(s, *this, #__VA_ARGS__, __VA_ARGS__); }


#endif /* classdump_h */
