//
//  wunion_find.h
//  ATC
//
//  Created by yuki on 2022/04/10.
//

template<class T>
struct wunion_find {
    vector<int> parent_map;
    vector<T> weight_map;

    wunion_find(int N): parent_map(N), weight_map(N, 0) {
        rep(i, N) parent_map[i] = i;
    }

    auto root(int x) -> int {
        if (parent_map[x] == x) return x;
        weight_map[x] += weight_map[parent_map[x]];
        return parent_map[x] = root(parent_map[x]);
    }
    
    auto weight(int x) -> T {
        root(x);
        return weight_map[x];
    }
    
    // weight(x) - weight(y) = w
    auto unite(int x, int y, T w) {
        auto rx = root(x), ry = root(y);
        if (rx != ry) {
            parent_map[rx] = ry;
            weight_map[rx] = w - weight(x) + weight(y);
        }
    }

    auto same(int x, int y) -> bool {
        return root(x) == root(y);
    }
};

template<class T> auto desc(wunion_find<T> v) {
    auto rs = unordered_map<int, vector<int>>();
    rep(i, v.parent_map.size()) rs[v.root(i)].push_back(i);
    desc(rs);
}
