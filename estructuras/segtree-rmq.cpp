// https://cses.fi/problemset/task/1649
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
#define rep(i,N)   for (int i = 0; i < int(N); i++)
#define scn(k,i,j) for (int k = int(i); k <= int(j); k++)
#define pb         push_back
#define endl       '\n'
// Pair
#define mp  make_pair
#define fst first
#define snd second
// Print
#define forall(it,v) for(auto it = v.begin(); it != v.end(); it++)
#define printall(v)  forall(x,v){cout << *x << " ";} cout << endl
#define printpair(p) cout << "(" << p.fst << ", " << p.snd << ")" << endl

template<class T> struct SegTree {
    vector<T>& arr; int N;
    T op (T a, T b) { return min(a,b); }
    T id = INT_MAX;
    vector<T> t;
    void make () {
        t.resize(N << 1); rep(i,N) t[i+N] = arr[i];
        for (int i = N - 1; i; i--) t[i] = op(t[i<<1], t[i<<1|1]);
    }
    void set (int i, int v) {
        for(t[i += N] = v; i > 1; i >>= 1) t[i>>1] = op(t[i], t[i^1]);
    }
    T q (int l, int r) {
        int res = id;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = op(res, t[l++]);
            if (r&1) res = op(res, t[--r]);
        } return res;
    }
};

int main (void) {
    ios::sync_with_stdio(0); cin.tie(0);

    int N, Q; vector<int> arr; cin >> N >> Q;
    rep(i,N) { int x; cin >> x; arr.pb(x); }

    SegTree<int> st = {arr, N}; st.make();

    rep(q,Q){
        int t; cin >> t;
        if (t == 1) {
            int k, u; cin >> k >> u; k--;
            st.set(k,u);
        }
        if (t == 2) {
            int i, j; cin >> i >> j; i--;
            cout << st.q(i,j) << endl;
        }
    }

    return 0;
}