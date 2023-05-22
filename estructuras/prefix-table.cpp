// https://judge.yosupo.jp/problem/static_range_sum
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

struct PTable {
    vector<i64> &arr; int N;
    vector<i64> pt;
    void make () {
        pt.resize(N);
        rep(i,N) pt[i] = !i ? arr[i] : pt[i-1] + arr[i];
    }
    i64 q (int i, int j) { return (--i < 0) ? pt[j] : pt[j] - pt[i]; }
};

int main (void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, Q; cin >> N >> Q;
    
    vector<i64> arr; arr.resize(N); rep(i,N) cin >> arr[i];

    PTable pt = {arr, N}; pt.make();

    rep(q,Q) {
        int i, j; cin >> i >> j; j--;
        cout << pt.q(i,j) << endl;
    }

    return 0;
}