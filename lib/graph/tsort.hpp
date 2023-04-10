//
//  tsort.hpp
//  ATC
//
//  Created by yuki on 2022/05/23.
//

#ifndef tsort_h
#define tsort_h

using Graph = vector<vector<int>>;

vector<int> tsort(Graph &G, vector<int> &indegree) {
    int V = (int)indegree.size();
    vector<int> res;

    queue<int> que; rep(i, V) if (indegree[i] == 0) que.push(i);

    while (que.size()) {
        auto v = que.front(); que.pop();
        rep(i, G[v].size()) {
            int u = G[v][i];
            indegree[u]--;
            if (indegree[u] == 0) que.push(u);
        }
        res.push_back(v);
    }

    return res;
}

#endif /* tsort_h */
