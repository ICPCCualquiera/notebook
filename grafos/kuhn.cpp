vector<int> kuhn_matching (AdjList& grafo) {
    vector<int> match(sz(grafo), -1);
    vector<bool> visitado(sz(grafo));

    function<bool(int)> kuhn_dfs = [&](int u) -> bool {
        if (visitado[u]) return false;
        visitado[u] = true;
        for (int v : grafo[u]) if (match[v] == -1 || kuhn_dfs(match[v])) {
            match[v] = u;
            return true;
        } return false;
    };

    forn(u, sz(grafo)) {
        visitado.assign(sz(grafo), false);
        kuhn_dfs(u);
    }

    return match;
}

int res = 0;
forn(u, sz(grafo)) if (match[u] != -1) res++;
cout << res / 2 << endl;