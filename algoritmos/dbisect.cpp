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

int tc; vector<vector<bool>> TC = {
    {0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
    {0, 0, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0},
    {0},
    {1}
};

i64 lsearch (i64 i, i64 j, bool (*pred)(i64)) {
    for (i64 k = i; k <= j; k++) if (pred(k)) return k;
    return i-1;
}

bool pred (i64 k) { return TC[tc][k]; }

i64 bsearch (i64 i, i64 j, bool (*pred)(i64)) {
    int d = i-1; while (!(i + 1 == j)) {
        i64 m = i + ((j - i) >> 1);
        pred(m) ? j = m : i = m;
    }
    if (pred(i)) return i;
    if (pred(j)) return j;
    return d;
}

int main (void) {
    ios::sync_with_stdio(0); cin.tie(0);

    for(tc = 0; tc < int(TC.size()); tc++) {
        int i = 0, j = TC[tc].size();
        assert(
            bsearch(i,j,pred) ==
            lsearch(i,j,pred)
        );
    }

    return 0;
}