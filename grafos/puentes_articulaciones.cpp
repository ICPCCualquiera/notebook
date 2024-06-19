auto GetPuentesYArticulaciones (Grafo& G) {
   int time = 0;
   vector<bool> visitado(sz(G));
   vector<int> tin(sz(G), -1), tlow(sz(G), -1), articulaciones;
   vector<pair<int, int>> puentes;
    auto dfs = [&](int u, int p) -> void {
        visitado[u] = true;
        tin[u] = tlow[u] = time++;
        int hijos = 0;
        for (int v : G[u]) {
            if (v == p) continue;
            if (visitado[v]) tlow[u] = min(tlow[u], tin[v]);
            else {
                dfs(v, u);
                hijos++;
                tlow[u] = min(tlow[u], tlow[v]);
                if (tlow[v] >  tin[u])
                    puentes.pb({u,v});
                if (tlow[v] >= tin[u] && p != -1)
                    articulaciones.pb(u);
            }
        }
        if (p == -1 && hijos > 1) articulaciones.pb(u);
    };
   forn(r, sz(G)) if (!visitado[r]) dfs(r, -1);
   return mt(puentes, articulaciones);
}