//
//  dijkstra.hpp
//  ATC
//
//  Created by yuki on 2022/04/11.
//

// コストが最小になるような経路を求める。

template<class T>
struct edge { T to, cost; };

template<class T>
using Graph = vector<vector<edge<T>>>;

vector<ll> dijk_ll(ll s, const Graph<ll> &graph) {
    using P = pair<ll, ll>;
    auto d = vector<ll>(graph.size(), LONG_LONG_MAX/2);
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

vector<int> dijk_ll(int s, const Graph<int> &graph) {
    using P = pair<int, int>;
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
