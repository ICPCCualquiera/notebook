// Metodo 1: Flood fill con un reverse al final
// Facil
int topovisit[maxn]; vector<int> topoorder;
void topodfs (int u) {
    topovisit[u] = 1;
    for (int v : adj[u]) if (!topovisit[v]) {
        topodfs(v); topoorder.push_back(u);
    }
}
void toposort (void) {
    forf(u,0,n) if(!topovisit[u]) topodfs(u);
    reverse(topoorder.begin(), topoorder.end());
}
// Metodo 2: Basado en BFS;
// priority_queue permite priorizar entre vertices con mismo nivel topologico 
int indegree[maxn]; vector<int> kahnsorder; void kahns () {
    priority_queue<int, vector<int>, greater<int>> pq;
    forf(u,0,n) for (int v : adj[u]) indegree[v]++;
    forf(u,0,n) if (!indegree[u]) pq.push(u);
    while (!pq.empty()) {
        int u = pq.top(); pq.pop(); kahnsorder.push_back(u);
        for (int v : adj[u]) { indegree[v]--; if (!indegree[v]) pq.push(v); }
    }
}