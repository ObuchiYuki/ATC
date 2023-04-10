//
//  dijkstra.hpp
//  ATC
//
//  Created by yuki on 2022/04/11.
//

// コストが最小になるような経路を求める。

struct edge { int to, cost; };
void desc(edge v) { cout << "(" << v.to << ", " << v.cost << ")"; }

using P = pair<int, int>;
using Graph = vector<vector<edge>>;

/// 全ての頂点に対する最短距離を求める。
/// 負の値がある場合は用いることができない -> そのばあbellman
auto dijk(int s, Graph &graph) -> vector<int> {
    auto d = vector<int>(graph.size(), INT_MAX/2);
    priority_queue<P, vector<P>, greater<P>> que;
    d[s] = 0;
    que.push({ 0, s });
    
    while(que.size()) {
        auto p = que.top(); que.pop();
        auto v = p.second;
        if (d[v] < p.first) continue;
        for (auto e: graph[v]) if (d[e.to] > d[v] + e.cost) {
            d[e.to] = d[v] + e.cost;
            que.push({ d[e.to], e.to });
        }
    }
    return d;
}
