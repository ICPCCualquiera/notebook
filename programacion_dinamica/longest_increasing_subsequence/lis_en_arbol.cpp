// Usa compresion de coordenadas y segtree RMQ (tomar el maximo)
vector<int> LIS (Grafo& G, vector<int>& valor_nodo, int root = 0) {
    auto C = Compress(valor_nodo);

    STNode def = { 0 };
    vector<STNode> hojas(sz(valor_nodo), def);
    STree dp = segtree_build(hojas);

    vector<int> res(sz(valor_nodo));

    segtree_update(dp, C[valor_nodo[root]], {1});
    auto dfs = [&](int u) {
        int x = C[valor_nodo[u]];
        int old = segtree_query(dp, x, x).val;
        int subres = {0};
        if (x-1 >= 0) subres = segtree_query(dp, 0, x-1).val;
        segtree_update(dp, x, {1 + subres});
        res[u] = segtree_query(dp, 0, sz(valor_nodo) - 1).val;
        for (int v : G[u]) dfs(v);
        segtree_update(dp, x, {old});
    };
    dfs(root);
 
   return res;
}