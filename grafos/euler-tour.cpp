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
    adj& g;
    vec<int> tour, de, tin, tout; int t;
    void dfs (int u, int h) {
        de.pb(h);
        tour.pb(u);    tin[u] = t++;
        forall(v,g[u]) dfs(*v, h+1);
        tour.pb(u);    tout[u] = t++;
        de.pb(h);
    }
    void make (int s) {
        tin.resize(g.size() * 2);
        tout.resize(g.size() * 2);
        dfs(s,0);
    }
};

int main (void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N; g.resize(N); scn(u,1,N-1) {
        int p; cin >> p; p--;
        g[p].pb(u);
    }

    ETour et = {g}; et.make(0);

    forall(v,et.tour) { cout << *v + 1 << " "; } cout << endl;

    forall(v,et.de) { cout << *v << " "; } cout << endl;

    printpair(mp(et.tin[1], et.tout[1]));

    return 0;
}