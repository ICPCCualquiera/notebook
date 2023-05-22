// https://cses.fi/problemset/task/1688/
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
#define rep(i,N)   for (int i = 0; i < int(N); i++)
#define scn(k,i,j) for (int k = int(i); k <= int(j); k++)
#define pb         push_back
#define endl       '\n'
#define mp  make_pair
#define fst first
#define snd second
#define forall(it,v) for(auto it = v.begin(); it != v.end(); it++)
#define printall(v)  forall(x,v){cout << *x << " ";} cout << endl
#define printpair(p) cout << "(" << p.fst << ", " << p.snd << ")" << endl

#define log2fl(x) (x ? 63 - __builtin_clzll(x) : -1)
typedef vector<vector<int>> adj;

struct LCA {
    adj& G; int N, R;
    int M; vector<int> e, f, d; adj st;
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
};

int main (void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, Q; cin >> N >> Q;
    adj G; G.resize(N);
    scn(v,1,N-1) { int p; cin >> p; p--; G[p].pb(v); }
    LCA lca = {G,N,0}; lca.make();
    rep(q,Q){
        int u, v; cin >> u >> v; u--, v--;
        cout << lca.q(u,v) + 1 << endl;
    }
    return 0;
}