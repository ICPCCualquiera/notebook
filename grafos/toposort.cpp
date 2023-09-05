using AdjList = vector<vector<int>>;

vector<int> Toposort (AdjList& G) {
    int N = G.size();
    vector<int> indegree(N), res;
    forn(u, N) for (int v : G[u]) indegree[v]++;
    // Elegir crierio de priorizacion cambiando el orden en el que se sacan
    // (por defecto el menor)
    using Bag = priority_queue<int, vector<int>, greater<int>>;
    Bag bag;
    forn(u, N) if(indegree[u] == 0) bag.push(u);
    while (bag.size()) {
        int u = bag.top();
        bag.pop();
        res.push_back(u);
        for (int v : G[u]) {
            indegree[v]--;
            if (indegree[v] == 0) bag.push(v);
        }
    }
    return res;
}