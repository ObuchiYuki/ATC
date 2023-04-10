//
//  bellmanford2.hpp
//  ATC
//
//  Created by yuki on 2022/04/12.
//

struct edge { ll from, to, cost; };
using Graph = vector<edge>;

const auto INF = LONG_LONG_MAX/2;

// 負閉路の検出も行うやつ
auto bellmanford2(int N, int M, Graph &graph) -> vector<ll> { // true to negcy
    auto d = vector<ll>(N, INF); d[0] = 0;
    
    int c=0; for (; c < N; c++) {
        auto update = false;
        for (auto e: graph) if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
            d[e.to] = d[e.from] + e.cost;
            update = true;
        }
        if (c > N || !update) break;
    }
    
    return d;
}

// dはbellmanford2の返り値
auto find_negative_loop(int N, int M, Graph &graph, vector<ll> d) -> vector<bool> {
    auto negative = vector<bool>(N, false);
    
    rep(i, N) {
        for (auto e: graph) {
            if(d[e.to] != INF && d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                negative[e.to] = true;
            }
            if(negative[e.from]) negative[e.to] = true;
        }
    }
    
    return negative;
}
