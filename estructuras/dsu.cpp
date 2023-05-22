// https://judge.yosupo.jp/problem/unionfind
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

struct DSU {
    vector<int> p, w; int nc;
    DSU (int n) {
        nc = n, p.resize(n), w.resize(n);
        rep(i,n) p[i] = i, w[i] = 1;
    }
    int f (int x) { return p[x] == x ? x : p[x] = f(p[x]); }
    void u (int x, int y) {
        x = f(x), y = f(y);
        if (x == y) return;
        if (w[x] > w[y]) swap(x,y);
        p[x] = y, w[y] += w[x];
    }
    bool c (int x, int y) { return f(x) == f(y); }
};

int main (void) {
    ios::sync_with_stdio(0); cin.tie(0);

    int N, Q; cin >> N >> Q;

    DSU dsu(N);
    rep(q,Q) {
        int t, u, v; cin >> t >> u >> v;
        if (t == 0) dsu.u(u,v);
        if (t == 1) cout << (dsu.c(u,v) ? 1 : 0) << endl;
    }

    return 0;
}