//
//  string.cpp
//  ATC
//
//  Created by yuki on 2022/04/25.
//

#include <string>

template<class C, class E>
auto split(C cont, E sep) -> vector<C> {
    vector<C> res; C chunk;
    rep(i, cont.size()) {
        if (cont[i] == sep) {
            if (chunk.size()) res.push_back(chunk);
            chunk.erase();
        } else {
            chunk.push_back(cont[i]);
        }
    }
    if (chunk.size()) res.push_back(chunk);
    return res;
}

