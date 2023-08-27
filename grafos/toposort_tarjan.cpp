using AdjList = vector<vector<int>>;

struct TarjanToposort {
    int N;
    AdjList& G;
    vector<int> visit, res;
    vector<int> Run () {
        visit.resize(N);
        forn(u, N) if (!visit[u]) dfs(u);
        reverse(all(res));
        return res;
    }
    void dfs (int u) {
        visit[u] = true;
        for (int v : G[u]) if (!visit[v]) dfs(v);
        res.push_back(u);
    }
};

// Usar asi:
int N;
AdjList G(N);

TarjanToposort tarjantoposort = {N, G};
vector<int> res = tarjantoposort.Run();