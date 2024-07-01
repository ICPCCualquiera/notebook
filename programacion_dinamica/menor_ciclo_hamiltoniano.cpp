ll MinimoCicloHamiltoniano (vector<vector<int>>& costo, int inicio) {
    vector<vector<ll>> memo(1 << sz(costo), vector<ll>(sz(costo), -1));

    auto dfs = [&](auto self, int mask, int actual) -> ll {
        if (mask == (1 << (sz(costo))) - 1) return (actual == inicio) ? 0 : LLONG_MAX / 2;

        if (memo[mask][actual] != -1) return memo[mask][actual];

        ll res = LLONG_MAX / 2;
        forn(proximo, sz(costo)) if (proximo != actual) {
            if (mask & (1 << proximo)) continue; // ya fue visitado
            ll costo_visitar = self(self, mask | (1 << proximo), proximo) + costo[actual][proximo];
            res = min(res, costo_visitar);
        }
        return memo[mask][actual] = res;
    };
    return dfs(dfs, 0, inicio);
}