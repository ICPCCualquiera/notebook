// https://cses.fi/problemset/task/1649
// Básico
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

int N, Q; vec<int> arr;

struct STree {
    vec<int> &a; int n;
    int id = INF; int op (int a, int b) { return min(a,b); }
    vec<int> t;
    int build (int v, int i, int j) {
        if (i == j) return t[v] = a[i];
        int m = (i + j) / 2;
        int l = build(2*v,   i,   m);
        int r = build(2*v+1, m+1, j);
        return t[v] = op(l,r);
    }
    int qur (int v, int i, int j, int qi, int qj) {
        if (qi > qj) return id;
        if (i == qi && j == qj) return t[v];
        int m = (i + j) / 2;
        int l = qur(2*v,   i,   m, qi,           min(m, qj));
        int r = qur(2*v+1, m+1, j, max(m+1, qi), qj);
        return op(l,r);
    } int qu (int i, int j) { return qur(1,0,n-1,i,j); }
    void upr (int v, int i, int j, int k, int u) {
        if (i == j) {t[v] = u; return;}
        int m = (i + j) / 2;
        k <= m ? upr(2*v, i, m, k, u) : upr(2*v+1, m+1, j, k, u);
        t[v] = op(t[2*v], t[2*v+1]);
    } void up (int k, int u) { upr(1,0,n-1,k,u); }
    void make () {
        n = a.size();
        t.assign(n*4, id);
        build(1,0,n-1);
    }
};

int main (void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> Q;
    rep(i,N) { int x; cin >> x; arr.pb(x); }
    STree st = {arr}; st.make();
    rep(q,Q) {
        int i, j; cin >> i >> j; i--, j--;
        cout << st.qu(i,j) << endl;
    }

    return 0;
}