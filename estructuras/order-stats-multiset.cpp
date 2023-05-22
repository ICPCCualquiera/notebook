// https://codeforces.com/gym/104375/problem/D
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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace  __gnu_pbds;
struct osms {
    int t = 0; tree<
        pair<int,int>, null_type, less<pair<int,int>>,
        rb_tree_tag, tree_order_statistics_node_update
    > ms;
    void add  (int x) { ms.insert(mp(x,t++)); }
    int  nle  (int x) { return ms.order_of_key(mp(x,-1)); }
    int  nleq (int x) { return ms.order_of_key(mp(x,INT_MAX)); }
    int  cnt  (int x) { return nleq(x) - nle(x); }
    int  ith  (int i) { return (*ms.find_by_order(i)).fst; }
    int size  (void)  { return ms.size(); }
};

int main (void) {
    ios::sync_with_stdio(0); cin.tie(0);

    osms S; int N, Q; cin >> N >> Q; rep(i,N) { int x; cin >> x; S.add(x); }

    rep(q,Q) {
        int t; cin >> t;
        if (t == 1) {
            int k; cin >> k;
            if (S.cnt(k)) continue;
            if (S.nle(k) == S.size()) { S.add(k); continue; }
            auto itp = S.ms.find_by_order(S.nleq(k));
            if (itp == end(S.ms)) continue;
            S.ms.erase(itp);
            S.add(k);
        }
        if (t == 2) {
            int a, b; cin >> a >> b;
            cout << S.nleq(b) - S.nle(a) << endl;
        }
    }

    return 0;
}