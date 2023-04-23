// https://judge.yosupo.jp/problem/static_range_sum
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
const int MAXN = 5e5;
const i64  INF = LLONG_MAX;
#define endl '\n'
#define rep(i,N) for (int i = 0; i < int(N); i++)
#define scn(k,i,j) for (int k = int(i); k <= int(j); k++)
#define forall(it,v) for(auto it = v.begin(); it != v.end(); it++)
#define printall(v) forall(x,v){cout << *x << " ";} cout << endl
#define vec vector
#define pb push_back
#define mp make_pair
#define printpair(p) cout << "(" << p.fst << ", " << p.snd << ")" << endl
#define fst first
#define snd second
#define log2fl(x) (x ? 63 - __builtin_clzll(x) : -1)
typedef vec<vec<int>> adj;
typedef vec<vec<pair<int,i64> > > wadj;

int N, Q; vec<i64> arr;

template<typename T>
class PTable {
    vec<T> pt;
    T opr (T a, T b) { return a + b; }
    T inv (T a, T b) { return a - b; }
    public:
    PTable (vec<T>& a) {
        pt.resize(a.size());
        rep(i,a.size()) pt[i] = !i ? a[i] : opr(pt[i-1], a[i]);
    }
    T q (int i, int j) { return (--i < 0) ? pt[j] : inv(pt[j], pt[i]); }
};

int main (void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    
    arr.resize(N); rep(i,N) cin >> arr[i];

    PTable<i64> pt(arr);

    rep(q,Q) {
        int i, j; cin >> i >> j; j--;
        cout << pt.q(i,j) << endl;
    }

    return 0;
}