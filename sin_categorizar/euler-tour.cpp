typedef vector<vector<int>> adj;
typedef vector<vector<pair<int,i64>>> wadj;

struct ETour {
    adj& G; int N, R;
    vector<int> t, f, d;
    void dfs (int u, int de = 0) {
        d[u] = de, f[u] = t.size(), t.pb(u);
        for (int v : G[u]) { dfs(v,de+1); t.pb(u); }
    }
    void make () { f.resize(N), d.resize(N), dfs(R); }
};

int main (void) {
    ios::sync_with_stdio(0); cin.tie(0);

    adj G; int N; cin >> N; G.resize(N);
    scn(u,1,N-1) {
        int p; cin >> p; p--;
        G[p].pb(u);
    }

    ETour et = {G, N, 0}; et.make();
    forall(v,et.t) { cout << *v + 1 << " "; } cout << endl;
    forall(v,et.t) { cout << et.d[*v] << " "; } cout << endl;
    forall(v,et.t) { cout << et.f[*v] << " "; } cout << endl;

    return 0;
}
/*
1 3 2 3 5 3 1 4 1 
0 1 2 1 2 1 0 1 0 
0 1 2 1 4 1 0 7 0
*/