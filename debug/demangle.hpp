//
//  demangle.h
//  UTP
//
//  Created by yuki on 2022/06/17.
//

#include <cxxabi.h>

const char* demangle(const char* v) {
    int s;
    return abi::__cxa_demangle(v, 0, 0, &s);
};

void ___replace(string &self, string subject, string target) {
    auto pos = self.find(subject, 0);
    while(pos != string::npos) {
        self.replace(pos, subject.size(), target);
        pos = self.find(subject, pos+1);
    }
}

string simple_demangle(const char* v) {
    string str(demangle(v));
    
    ___replace(str, "std::__1::", "");
    ___replace(str, "std::", "");
    ___replace(str, "> >", ">>");
    ___replace(str, "basic_string<char, char_traits<char>, allocator<char>>", "string");
    
    return str;
};

#define type_print(T) print(simple_demangle(typeid(T).name()))
