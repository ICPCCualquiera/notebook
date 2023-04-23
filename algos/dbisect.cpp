#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
const int MAXN = 5e5;
const i64  INF = LLONG_MAX;
#define endl '\n'
#define rep(i,N) for (int i = 0; i < int(N); i++)
#define scn(k,i,j) for (int k = int(i); k <= int(j); k++)
#define fat(x,v) for (auto x : v)
#define vec vector
#define pb push_back
#define sz size()
#define mp make_pair
#define printpair(p) cout << "(" << p.fst << ", " << p.snd << ")";
#define fst first
#define snd second
#define log2fl(x) (x ? 63 - __builtin_clzll(x) : -1)

void dbisect (i64& i, i64& j, bool (*pred)(i64)) {
    while (!(i + 1 == j)) {
        i64 m = i + (j - i) / 2;
        pred(m) ? j = m : i = m;
    }
}
pair<bool, i64> dfirsttrue (i64 i, i64 j, bool (*pred)(i64)) {
    dbisect(i, j, pred);
    if (pred(i)) return mp(true, i);
    if (pred(j)) return mp(true, j);
    return mp(false, -1L);
}
pair<bool, i64> dlastfalse (i64 i, i64 j, bool (*pred)(i64)) {
    dbisect(i, j, pred);
    if (!pred(j)) return mp(true, j);
    if (!pred(i)) return mp(true, i);
    return mp(false, -1L);
}

pair<bool, i64> lsearch_ft (i64 i, i64 j, bool (*pred)(i64)) {
    scn(k,i,j) if (pred(k)) return mp(true, k);
    return mp(false, -1);
}

pair<bool, i64> lsearch_lf (i64 i, i64 j, bool (*pred)(i64)) {
    for (i64 k = j; k >= i; k--) if (!pred(k)) return mp(true, k);
    return mp(false, -1);
}

vec<i64> arr = {-9, -9, -7, -4, -2, -1, 1, 1, 3, 4, 6, 8};

i64 z = 0;
bool arr_i_geq_z (i64 i) { return arr[i] >= z; }

int main (void) {
    ios::sync_with_stdio(0); cin.tie(0);

    scn(y,-10,9) {
        z = y;
        scn(i,0,arr.sz - 1) scn(j,i+1,arr.sz - 1) {
            auto p1 = lsearch_lf(i, j, arr_i_geq_z);
            auto p2 = dlastfalse(i, j, arr_i_geq_z);
            if (p1.snd != p2.snd) { // error
                printpair(mp(i,j)) cout << " ";
                printpair(p1); cout << " ";
                printpair(p2); cout << endl;
                return 0;
            }
        }
    }

    return 0;
}