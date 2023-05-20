/*
 *
 *
 *
 *
 * ESTO TIRA WRONG ANSWER
 * DEBUGGEAR POR FAVOR
 *
 *
 *
 *
*/

// https://codeforces.com/gym/104375/problem/D
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

// TODO:
// Hace falta esto?
// No se puede hacer lower_bound(A.begin(), A.end(), x) - A.begin() directamente?
int nle (vector<int>& A, int x) {
    auto lb = lower_bound(A.begin(), A.end(), x);
    if (lb == A.end()) return A.size();
    return lb - A.begin();
}

// TODO: ídem arriba
int nleq (vector<int>& A, int x) {
    auto ub = upper_bound(A.begin(), A.end(), x);
    if (ub == A.end()) return A.size();
    return ub - A.begin();
}

int main (void) {
    ios::sync_with_stdio(0); cin.tie(0);

    int N, Q, m = -1; cin >> N >> Q;
    vector<int> A; rep(i,N) { int x; cin >> x; A.pb(x); m = max(m, x); } sort(A.begin(), A.end());

    rep(q,Q) {
        int t; cin >> t;
        if (t == 1) {
            int k; cin >> k;
            if (binary_search(A.begin(), A.end(), k)) continue;
            if (k > m) { A.pb(k); m = max(m, k); continue; }
            auto itp = upper_bound(A.begin(), A.end(), k);
            if (itp == end(A)) continue;
            *itp = k;
        }
        if (t == 2) {
            int a, b; cin >> a >> b;
            cout << nleq(A,b) - nle(A,a) << endl;
        }
    }

    return 0;
}