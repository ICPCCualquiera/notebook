using AdjList = vector<vector<int>>;

bool es_bipartito (AdjList& G) {
    vector<int> color(G.size(), -1);
    color[0] = 0;
    queue<int> bag;
    for (bag.push(0); bag.size();) {
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