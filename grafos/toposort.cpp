vector<int> Toposort (Grafo& G) {
    vector<int> indegree(sz(G)), res;
    forn(u, sz(G)) for (int v : G[u]) indegree[v]++;
    // Elegir crierio de priorizacion cambiando el orden en el que se
    // sacan (por defecto el menor)
    using Bag = priority_queue<int, vector<int>, greater<int>>;
    Bag bag;
    forn(u, sz(G)) if(indegree[u] == 0) bag.push(u);
    while (sz(bag)) {
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