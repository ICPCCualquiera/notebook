#pragma region // Dijkstra
using GrafoPond = vector<vector<pair<ll, int>>>;
auto Dijkstra (GrafoPond& grafo, int origen) {
    vector<ll>  dist(sz(grafo), LLONG_MAX);
    vector<int> padre(sz(grafo), -1);
    dist[origen] = 0;
    padre[origen] = origen;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> visitados;
    for (visitados.push({0, origen}); visitados.size();) {
        auto [du, u] = visitados.top();
        visitados.pop();
        if (du > dist[u]) continue; // (du,u) es un valor viejo
        for (auto [w, v] : grafo[u]) {
            ll nueva_dist = du + w;
            if (nueva_dist >= dist[v]) continue; // no mejora
            dist[v] = nueva_dist;
            padre[v] = u;
            visitados.push({nueva_dist, v});
        }
    }
    return mt(dist, padre);
}
#pragma endregion