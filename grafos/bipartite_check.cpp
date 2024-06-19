bool EsBipartito (Grafo& G) {
    vector<int> color(sz(G), -1);
    color[0] = 0;
    queue<int> bag;
    for (bag.push(0); sz(bag);) {
        int u = bag.front();
        bag.pop();
        for (int v : G[u]) {
            if (color[u] == color[v]) return false;
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                bag.push(v);
            }
        }
    }
    return true;
}