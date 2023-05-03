// Basico
#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for (int i = 0; i < int(N); i++)
#define scn(k,i,j) for (int k = int(i); k <= int(j); k++)
#define vec vector
#define pb push_back
#define endl '\n'
// i64 + INF
using i64 = int64_t;
const i64  INF = LLONG_MAX;
// Adj
typedef vec<vec<int>> adj;
typedef vec<vec<pair<int,i64> > > wadj;
// Pair
#define mp make_pair
#define fst first
#define snd second
// Print
#define forall(it,v) for(auto it = v.begin(); it != v.end(); it++)
#define printall(v) forall(x,v){cout << *x << " ";} cout << endl
#define printpair(p) cout << "(" << p.fst << ", " << p.snd << ")" << endl
// Misc.
const int MAXN = 5e5;
#define log2fl(x) (x ? 63 - __builtin_clzll(x) : -1)

adj g; int N;

struct ETour {
    vector<vector<int>>& adj; int N;
    vector<int> tour, first, depth;
    void dfs (int u, int d = 0) {
        depth[u] = d;
        first[u] = tour.size();
        tour.push_back(u);
        for (int v : adj[u]) { dfs(v,d+1); tour.push_back(u); }
    }
    void make (int r) {
        first.resize(N);
        depth.resize(N);
        dfs(r);
    }
};

int main (void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N; g.resize(N); scn(u,1,N-1) {
        int p; cin >> p; p--;
        g[p].pb(u);
    }

    ETour et = {g, N}; et.make(0);

    forall(v,et.tour) { cout << *v + 1 << " "; } cout << endl;

    forall(v,et.tour) { cout << et.depth[*v] << " "; } cout << endl;

    forall(v,et.tour) { cout << et.first[*v] << " "; } cout << endl;

    return 0;
}