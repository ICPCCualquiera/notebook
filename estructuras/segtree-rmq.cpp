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

template<class T> struct SegTree {
    vector<T>& arr; int N;
    T op (T a, T b) { return min(a,b); }
    T ne = INT_MAX;
    vector<T> tree;
    T build (int v, int i, int j) {
        if (i == j) return tree[v] = arr[i];
        int m = (i + j) / 2;
        T u1 = build(2*v, i, m);
        T u2 = build(2*v+1, m+1, j);
        return tree[v] = op(u1,u2);
    }
    T query (int v, int i, int j, int ti, int tj) {
        if ( j < ti || tj <   i) return ne;
        if (ti <= i &&  j <= tj) return tree[v];
        int m = (i + j) / 2;
        T u1 = query(2*v, i, m, ti, tj);
        T u2 = query(2*v+1, m+1, j, ti, tj);
        return op(u1, u2);
    } T qu (int i, int j) { return query(1, 0, N-1, i, j); }
    T update (int v, int i, int j, int k, int u) {
        if (k < i || j < k) return tree[v];
        if (i == j) return tree[v] = u;
        int m = (i + j) / 2;
        T u1 = update(2*v, i, m, k, u);
        T u2 = update(2*v+1, m+1, j, k, u);
        return tree[v] = op(u1,u2);
    } void up (int k, int u) { update(1, 0, N-1, k, u); }
    void make (void) {
        tree.resize(N << 2);
        build(1, 0, N-1);
    }
};

int main (void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> Q;
    rep(i,N) { int x; cin >> x; arr.pb(x); }
    SegTree<int> st = {arr, N}; st.make();
    rep(q,Q){
        int t; cin >> t;
        if (t == 1) {
            int k, u; cin >> k >> u; k--;
            st.up(k,u);
        }
        if (t == 2) {
            int i, j; cin >> i >> j; i--, j--;
            cout << st.qu(i,j) << endl;
        }
    }

    return 0;
}