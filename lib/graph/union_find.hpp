//
//  union_find.cpp
//  ATC
//
//  Created by yuki on 2022/04/08.
//

// グループ分けをする。

struct union_find {
    vector<int> parent;

    union_find(int N): parent(N) {
        iota(parent.begin(), parent.end(), 0);
    }
    auto root(int x) -> int {
        if (parent[x] == x) return x;
        return parent[x] = root(parent[x]);
    }
    auto unite(int x, int y) {
        auto rx = root(x), ry = root(y);
        if (rx != ry) this->parent[rx] = ry;
    }
    auto same(int x, int y) -> bool {
        return root(x) == root(y);
    }
};

auto desc(union_find uf) {
    auto rs = unordered_map<int, vector<int>>();
    rep(i, uf.parent.size()) rs[uf.root(i)].push_back(i); desc(rs);
}


