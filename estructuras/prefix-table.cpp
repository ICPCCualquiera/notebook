// https://judge.yosupo.jp/problem/static_range_sum
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

template<class T> struct PTable {
    vec<T> &arr; int N;
    vec<T> pt;
    T opr (T a, T b) { return a + b; }
    T inv (T a, T b) { return a - b; }
    void make () {
        pt.resize(N);
        rep(i,N) pt[i] = !i ? arr[i] : opr(pt[i-1], arr[i]);
    }
    T q (int i, int j) { return (--i < 0) ? pt[j] : inv(pt[j], pt[i]); }
};

int main (void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, Q; cin >> N >> Q;
    
    vec<i64> arr; arr.resize(N); rep(i,N) cin >> arr[i];

    PTable<i64> pt = {arr, N}; pt.make();

    rep(q,Q) {
        int i, j; cin >> i >> j; j--;
        cout << pt.q(i,j) << endl;
    }

    return 0;
}