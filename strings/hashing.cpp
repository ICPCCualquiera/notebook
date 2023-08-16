// https://codeforces.com/group/hzSLIARNBN/contest/465596/submission/217383572
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

const int MAXN = 1e4;
const i64 mod = 1e9 + 9;
const int pri = 27;

struct Data {
    int V;
    vector<int> C[MAXN];
    char L[MAXN];
    int in[MAXN], out[MAXN];
    string S;
    vector<i64> RH;
}; Data G1, G2;

int dfstime; void encode (Data& G, int u) {
    G.in[u] = dfstime; dfstime += 2;
    G.S.pb('('); G.S.pb(G.L[u]);
    for (int v : G.C[u]) encode(G, v);
    G.S.pb(G.L[u]); G.S.pb(')');
    dfstime++; G.out[u] = dfstime; dfstime++;    
}

i64 P[4*MAXN+1]; void get_primes () {
    P[0] = 1; scn(i,1,4*MAXN-1) P[i] = (P[i-1] * pri) % mod;
}

vector<i64> get_rolling_hash (string& s) {
    vector<i64> rh(s.size() + 1);
    rh[0] = 0; rep(i,s.size()) rh[i+1] = (rh[i] * pri % mod + s[i] - 'A') % mod;
    return rh;
}

i64 hash_range_query (vector<i64>& rh, int i, int j) { j++; return (rh[j] - (rh[i] * P[j - i] % mod) + mod) % mod; }

void read_tree (Data& G) {
    rep(v,G.V) {
        char c; cin >> c; G.L[v] = c;
        int p; cin >> p;
        if (p != -1) G.C[p].pb(v);
    }
}

int main (void) {
    ios::sync_with_stdio(0); cin.tie(0);

    get_primes();

    int TC; cin >> TC; rep(tc,TC) {
        cin >> G1.V >> G2.V;

        read_tree(G1);
        read_tree(G2);

        dfstime = 0; encode(G1, 0);
        dfstime = 0; encode(G2, 0);

        G1.RH = get_rolling_hash(G1.S);
        G2.RH = get_rolling_hash(G2.S);

        set<i64> H1; rep(v,G1.V)
            H1.insert(hash_range_query(G1.RH, G1.in[v], G1.out[v]));

        int res = 0; rep(v,G2.V) {
            int i = G2.in[v], j = G2.out[v];
            i64 h = hash_range_query(G2.RH, i ,j);
            if (H1.count(h)) res = max(res, j - i + 1);
        }

        cout << res / 4 << endl;

        G1.S.clear(); rep(i,G1.V) G1.C[i].clear();
        G2.S.clear(); rep(i,G2.V) G2.C[i].clear();
    }

    return 0;
}