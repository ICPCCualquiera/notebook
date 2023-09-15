#define log2fl(x) (x ? 63 - __builtin_clzll(x) : -1)
using AdjList = vector<vector<int>>;
 
struct LCA {
    AdjList& G; int N, R; // Grafo (ROOTEADO), #vertices y raiz
    int M; vector<int> e, f, d; AdjList st;
    void dfs (int u, int de = 0) {
        d[u] = de, f[u] = e.size(), e.pb(u);
        for (int v : G[u]) dfs(v,de+1), e.pb(u);
    }
    int op (int a, int b) {
        if (a == -1) return b;
        if (b == -1) return a;
        return d[a] < d[b] ? a : b;
    }
    void make () {
        f.resize(N), d.resize(N), dfs(R), M = e.size();
        st.resize(20, vector<int>(M));
        st[0] = e; scn(w,1,19) scn(i,0,M - (1 << w))
            st[w][i] = op(st[w-1][i], st[w-1][i + (1 << (w-1))]);
    }
    int q (int u, int v) {
        int i = f[u], j = f[v];
        if (i > j) swap(i,j);
        int w = log2fl(j - i + 1);
        return op(st[w][i], st[w][j - (1 << w) + 1]);
    }
    int di (int u, int v) {
        int c = q(u,v);
        return d[u] + d[v] - 2*d[c];
    }
};

bool visited[500001]; void rootear (int u) {
    visited[u] = 1;
    for (int v : grafo_original[u]) if (!visited[v]) {
        grafo_rooteado[u].pb(v);
        rootear(v);
    }
}


// Usar asi:
rootear(r);
LCA lca = {grafo_rooteado, N, r}; lca.make();