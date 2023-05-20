// https://judge.yosupo.jp/problem/staticrmq
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

#define log2fl(x) (x ? 63 - __builtin_clzll(x) : -1)
struct STable {
    vector<int>& arr; int N;
    vector<vector<int>> st;
    int op (int a, int b) { return min(a,b); }
    void make () {
        st.resize(20, vector<int>(N));
        st[0] = arr; scn(w,1,19) scn(i,0,N - (1 << w))
            st[w][i] = op(st[w-1][i], st[w-1][i + (1 << (w-1))]);
    }
    int q (int i, int j) {
        int w = log2fl(j - i + 1);
        return op(st[w][i], st[w][j - (1 << w) + 1]);
    }
};

int main (void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, Q; cin >> N >> Q;
    vector<int> arr; arr.resize(N); rep(i,N) cin >> arr[i];

    STable st = {arr, N}; st.make();

    rep(q,Q) {
        int i, j; cin >> i >> j; j--;
        cout << st.q(i,j) << endl;
    }

    return 0;
}