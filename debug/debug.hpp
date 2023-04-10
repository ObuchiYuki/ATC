//
//  debug.hpp
//  ATC
//
//  Created by yuki on 2022/04/07.
//

#ifndef debug_h
#define debug_h

#define STRINGS_AS_FIELD 1
//#define PAIR_AS_INIT 1

using ss = stringstream;

#include "measure.hpp"
#include "print.hpp"
#include "classdump.hpp"

void _main();

int main() {
    auto file = "input.txt";
    auto ifs = ifstream(file); cin.rdbuf(ifs.rdbuf());
    cout << ifstream(file).rdbuf() << endl;
    cout << setprecision(8) << boolalpha;
    _main();
}

#endif /* debug_h */
