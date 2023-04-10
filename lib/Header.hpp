//
//  Header.hp
//  ATC
//
//  Created by yuki on 2023/04/06.
//

template<class T>
struct pcompare {
    bool operator () (const T& a, const T& b) { return a.first < b.first; }
};

