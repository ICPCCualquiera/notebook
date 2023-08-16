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

const int maxn = 5e5;
int N, M, s, t;
vector<pair<int,i64>> adj[maxn];

const i64 INF = 1e18;
i64 D[maxn];
void dijkstra () {
    rep(i,N) D[i] = INF;
    D[s] = 0;
    priority_queue<pair<i64,int>, vector<pair<i64,int>>, greater<pair<i64,int>>> pq; pq.push(mp(0,s));
    while (pq.size()) {
        int u = pq.top().snd; pq.pop();
        cout << u << endl;
        for (auto dv : adj[u]) {
            int v = dv.fst, d = dv.snd;
            if (D[v] > D[u] + d) {
                D[v] = D[u] + d;
                pq.push(mp(D[v], v));
            }
        }
    }
}

int main (void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M >> s >> t;
    rep(i,M){
        int u, v, d; cin >> u >> v >> d;
        adj[u].pb(mp(v,d));
    }

    dijkstra();

    cout << D[t] << endl;

    return 0;
}