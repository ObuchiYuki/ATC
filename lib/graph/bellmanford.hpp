//
//  bellmanford.hpp
//  ATC
//
//  Created by yuki on 2022/04/12.
//

// sから全ての頂点への最短経路を求める
// (trueならnagative loop)
using scala = int;

struct edge { scala from, to, cost; };
void desc(edge v) { cout << "(" << v.from << ", " << v.to << ", " << v.cost << ")"; }

using Graph = vector<edge>;
const auto INF = numeric_limits<scala>::max()/2;

pair<vector<scala>, bool> bellmanford(int s, int V, int E, Graph &graph) {
    vector<scala> d(V, INF);
    d[s] = 0;
    
    int c = 0;
    bool nagative = false;
    while (true) {
        auto update = false;
        for (auto e: graph) if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
            d[e.to] = d[e.from] + e.cost;
            update = true;
        }
        if (!update) break;
        if (c > V) { nagative = true; break; }
        c++;
    }
    
    return { d, nagative };
}
