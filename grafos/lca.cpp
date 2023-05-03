// https://cses.fi/problemset/task/1688/
// Basico
#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for (int i = 0; i < int(N); i++)
#define scn(k,i,j) for (int k = int(i); k <= int(j); k++)
#define vec vector
#define pb push_back
#define endl '\n'
// INF
const int INF = INT_MAX;
using i64 = int64_t;
const i64 lINF = LLONG_MAX;
// Adj
typedef vec<vec<int>> adj;
typedef vec<vec<pair<int,i64>>> wadj;
// Pair
#define mp make_pair
#define fst first
#define snd second
// Print
#define forall(it,v) for(auto it = v.begin(); it != v.end(); it++)
#define printall(v)  forall(x,v){cout << *x << " ";} cout << endl
#define printpair(p) cout << "(" << p.fst << ", " << p.snd << ")" << endl
// Misc
const int MAXN = 5e5;
#define log2fl(x) (x ? 63 - __builtin_clzll(x) : -1)

struct LCA {
    vec<vec<int>>& adj; int N, M;
    vec<int> tour, first, depth, tree;
    void dfs (int u, int d = 0) {
        depth[u] = d; first[u] = tour.size(); tour.pb(u);
        for (int v : adj[u]) { dfs(v,d+1); tour.pb(u); }
    }
    int op (int a, int b) {
        if (a == -1) return b;
        if (b == -1) return a;
        return depth[a] < depth[b] ? a : b;
    }
    int build (int v, int i, int j) {
        if (i == j) return tree[v] = tour[i];
        int m = (i + j) / 2;
        int lc = build(2*v, i, m);
        int rc = build(2*v+1, m+1, j);
        return tree[v] = op(lc,rc);
    }
    int query (int v, int i, int j, int ti, int tj) {
        if ( j <  ti || tj <   i) return -1;
        if (ti <=  i &&  j <= tj) return tree[v];
        int m = (i + j) / 2;
        int lc = query(2*v, i, m, ti, tj);
        int rc = query(2*v+1, m+1, j, ti, tj);
        return op(lc,rc);
    }
    void make (int r) {
        first.resize(N); depth.resize(N);
        dfs(r); M = tour.size();
        tree.assign(4*M, -1); build(1, 0, M-1);
    }
    int lca (int u, int v) {
        int i = first[u], j = first[v];
        if (i > j) swap(i,j);
        return query(1, 0, M-1, i, j);
    }
};

int main (void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, Q; cin >> N >> Q;
    vec<vec<int>> G; G.resize(N);
    scn(v,1,N-1) { int p; cin >> p; p--; G[p].pb(v); }
    LCA lca = {G,N}; lca.make(0);
    rep(q,Q){
        int u, v; cin >> u >> v; u--, v--;
        cout << lca.lca(u,v) + 1 << endl;
    }
    return 0;
}