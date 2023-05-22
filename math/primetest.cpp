// https://codeforces.com/problemset/problem/230/B
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

struct primetest {
    bool c[1000001]; vector<int> p;
    primetest () {
        p.reserve(1<<16); scn(i,2,1000000) if (!c[i]) {
            p.pb(i); for (int j = 2; i*j < 1000001; j++) c[i*j] = 1;
        }
    }
    bool isprime (int x) {
        for (int i = 0, d = p[i]; d*d <= x; d = p[++i])
            if (!(x % d)) return false;
        return x >= 2;
    }
};

i64 isqrt (i64 x) {
    i64 s = 0; for (i64 k = 1 << 30; k; k >>= 1)
        if ((s+k)*(s+k) <= x) s += k;
    return s;
}

int main (void) {
    ios::sync_with_stdio(0); cin.tie(0);

    primetest prt;

    int TC; cin >> TC; rep(tc,TC) {
        i64 n; cin >> n;
        i64 s = isqrt(n);
        cout << ((s*s == n) && prt.isprime(s) ? "YES" : "NO") << endl;
    }

    return 0;
}