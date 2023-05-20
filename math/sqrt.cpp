// https://codeforces.com/contest/1809/problem/B
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

i64 isqrt (i64 x) {
    i64 s = 0; for (i64 k = 1 << 30; k; k >>= 1)
        if ((s+k)*(s+k) <= x) s += k;
    return s;
}

int main (void) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int TC; cin >> TC; rep(tc,TC) {
        i64 n; cin >> n;
        i64 res = isqrt(n); if (res * res == n) res--;
        cout << res << endl;
    }

    return 0;
}