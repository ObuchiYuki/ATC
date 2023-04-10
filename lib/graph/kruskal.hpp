//
//  kruskal.hpp
//  ATC
//
//  Created by yuki on 2022/04/11.
//

struct union_find {
    vector<int> parent_map;

    union_find(int N): parent_map(N) {
        rep(i, N) parent_map[i] = i;
    }

    auto root(int x) -> int {
        if (parent_map[x] == x) return x;
        return parent_map[x] = root(parent_map[x]);
    }

    auto unite(int x, int y) {
        auto rx = root(x), ry = root(y);
        if (rx != ry) this->parent_map[rx] = ry;
    }

    auto same(int x, int y) -> bool {
        return root(x) == root(y);
    }
};

struct edge { int from, to, cost; };
using Graph = vector<edge>;

ll kruskal(int s, int V, Graph &graph) {
    sort(graph.begin(), graph.end(), [](edge a, edge b) {
        return a.cost < b.cost;
    });
    
    auto uf = union_find(V);
    ll total = 0;

    rep(i, graph.size()) {
        auto e = graph[i];
        if (!uf.same(e.from, e.to)) {
            uf.unite(e.from, e.to);
            total += e.cost;
        }
    }

    return total;
}
