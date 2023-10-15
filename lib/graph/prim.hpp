//
//  prim.hpp
//  ATC
//
//  Created by yuki on 2022/04/11.
//

/// 最小全域木の重みを計算する
struct edge { int to, cost; };
using Graph = vector<vector<edge>>;
using P = pair<ll, ll>;

// IaAESbuVrmYXmPfSDt7LJ1U4MDDlatpK

auto prim(int s, Graph &graph) -> ll {
    auto used = vector<bool>(graph.size(), false);
    auto que = priority_queue<P, vector<P>, greater<P>>();
    que.push({ 0, s });
    ll total = 0;
    
    while (que.size()) {
        auto p = que.top(); que.pop();
        auto v = p.second;
        
        if (used[v]) continue; used[v] = true;
        total += p.first;
        
        for (auto e: graph[v]) if (!used[e.to]) que.push({ e.cost, e.to });
    }
    
    return total;
}
