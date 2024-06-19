Grafo DAGCondensado (Grafo& G) {
    vector<bool> visitado(sz(G));

    vector<int> orden;
    auto get_orden = [&](int u) -> void {
        visitado[u] = true;
        for (int v : G[u]) if (!visitado[v]) get_orden(v);
        orden.pb(u);
    };
    forn(u, sz(G)) if (!visitado[u]) get_orden(u);
    reverse(all(orden));

    Grafo T(sz(G));
    forn(u, sz(G)) for (int v : G[u]) T[v].pb(u);

    vector<int> comp, raiz(sz(G)), raices;
    auto extraer_comp = [&](int u) -> void {
        visitado[u] = true;
        comp.pb(u);
        for (int v : T[u]) if (!visitado[v]) extraer_comp(v);
    };

    visitado.assign(sz(G), false);
    for (int u : orden) if (!visitado[u]) {
        extraer_comp(u);
        int r = comp.front();
        for (int v : comp) raiz[v] = r;
        raices.pb(r);
        comp.clear();
    }

    // Opcion 1: hacer compresion de coordenadas: O(nlogn) lento
    int c = 0;
    map<int, int> coords;
    for (int   r :  raices) coords[r];
    for (auto& e : coords) e.snd = c++;
    Grafo SCC(raices.size());
    forn(u, sz(G)) for (int v : G[u]) {
        int ru = coords[raiz[u]], rv = coords[raiz[v]];
        if (ru != rv) SCC[ru].pb(rv);
    }

    return SCC;

    // Opcion 2: no hacer compresion y devolver raices (rapido)
    // AdjList SCC(sz(G));
    // forn(u, sz(G)) for (auto [v, w] : G[u]) {
        // int ru = raiz[u], rv = raiz[v];
        // if (ru != rv) SCC[ru].pb({rv, w});
        // else (RC[ru]) += R(w);
    // }
}