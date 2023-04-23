// https://judge.yosupo.jp/problem/staticrmq
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

int N, Q; vec<int> arr;

template<typename T>
class STable {
    vec<vec<T>> st;
    T op (T a, T b) { return min(a,b); }
    public:
    STable (vec<T>& a) {
        st.resize(20, vec<T>(a.size()));
        st[0] = a; scn(w,1,19) scn(i,0,a.size()-(1<<w))
            st[w][i] = op(st[w-1][i], st[w-1][i+(1<<(w-1))]);
    }
    T q (int i, int j) {
        int w = log2fl(j - i + 1);
        return op(st[w][i], st[w][j - (1 << w) + 1]);
    }
};

int main (void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;

    arr.resize(N); rep(i,N) cin >> arr[i];

    STable<int> st(arr);

    rep(q,Q) {
        int i, j; cin >> i >> j; j--;
        cout << st.q(i,j) << endl;
    }

    return 0;
}