#pragma region // Menores dos distancias (dijkstra)
using GrafoPond = vector<vector<pair<ll, int>>>;
auto MenoresDosDistancias (GrafoPond& grafo, int origen) {
    vector<ll> dist1(sz(grafo), LLONG_MAX), dist2(sz(grafo), LLONG_MAX);
    dist1[origen] = 0; dist2[origen] = LLONG_MAX;
    auto update_dist = [&](ll nueva_dist, int v) -> bool {
        if (nueva_dist < dist1[v]) {
            dist2[v] = dist1[v];
            dist1[v] = nueva_dist;
            return true;
        }
        else if (nueva_dist < dist2[v]) { // && dist1[v] < nueva_dist para tomar dists. distintas
            dist2[v] = nueva_dist;
            return true;
        }
        return false;
    };
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> visitados;
    for (visitados.push({0, origen}); visitados.size();) {
        auto [du, u] = visitados.top();
        visitados.pop();
        if (du > dist2[u]) continue; // (du,u) es un valor viejo
        for (auto [w, v] : grafo[u]) {
            ll nueva_dist = du + w;
            bool mejora = update_dist(nueva_dist, v);
            if (mejora) visitados.push({nueva_dist, v});
        }
    }
   return mt(dist1, dist2);
}
#pragma endregion