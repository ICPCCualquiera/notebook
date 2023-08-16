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

template<class T>
vector<i64> get_prefix_sums_rqpu (vector<T>& arr) {
    vector<i64> ps(arr.size() + 1);
    ps[0] = 0; rep(i,arr.size()) ps[i+1] = ps[i] + arr[i];
    return ps;
}
i64  prefix_sum_range_query  (vector<i64>&ps, int i, int j) { return ps[++j] - ps[i]; }
void prefix_sum_point_update (vector<i64>&ps, int i, int v) { scn(k, i, ps.size() - 1) ps[k] += v; }

template<class T>
vector<i64> get_prefix_sums_rupq (vector<T>& arr) {
    vector<i64> ps(arr.size() + 1);
    rep(i,arr.size()) ps[i] += arr[i], ps[i+1] -= arr[i];
    return ps;
}
void       prefix_sum_range_update (vector<i64>&ps, int i, int j, int v) { ps[i] += v; ps[++j] -= v; }
i64        prefix_sum_point_query  (vector<i64>&ps, int i) { i64 res = 0; rep(k, i + 1) { res += ps[k]; } return res; }
vecor<i64> prefix_rum_rupq_rebuild (vector<i64>&ps) {
    vector<i64> arr(ps.size() - 1);
    arr[0] = ps[0]; rep(i, arr.size() - 1) arr[i+1] = arr[i] + ps[i+1];
    return arr;
}


int main (void) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    // https://judge.yosupo.jp/problem/static_range_sum
    // int N, Q; cin >> N >> Q;
    // vector<i64> arr(N); rep(i,N) cin >> arr[i];
    // vector<i64> ps = get_prefix_sums_rqpu(arr);
    // rep(q,Q) {
    //     int i, j; cin >> i >> j; j--;
    //     cout << prefix_sum_range_query(ps, i, j) << endl;
    // }

    // int N, Q; cin >> N >> Q;
    // vector<i64> arr(N); rep(i,N) cin >> arr[i];
    // vector<i64> ps = get_prefix_sums_rupq(arr);
    // rep(q,Q) {
    //     int k; cin >> k;
    //     if (k == 1) {
    //         int i, j, v; cin >> i >> j >> v; i--, j--;
    //         prefix_sum_range_update(ps, i, j, v);
    //     if (k == 2) {
    //     }
    //         int i; cin >> i; i--;
    //         cout << prefix_sum_point_query(ps, i) << endl;
    //     }
    // }

    return 0;
}