#define forf(i,s,e) for (int i = int(s); i < int(e); i++)
using namespace std;

const int maxn = int(5e5+1);
int n, m; vector<int> adj[maxn];

deque<int> kosaorder; int kosavisit[maxn];
void kosajaru1 (int u) { kosavisit[u] = 1; for (int v : adj[u]) if (!kosavisit[v]) kosajaru1(v); kosaorder.push_front(u); }
vector<int> tadj[maxn]; void kosajaru2 (void) { forf(u,0,n) for (int v : adj[u]) tadj[v].push_back(u); }
int kosaroot[maxn]; vector<vector<int>> kosacomp;
void kosajaru3 (int u, int r) { kosavisit[u] = 1; kosacomp.back().push_back(u); kosaroot[u] = r; for (int v : tadj[u]) if (!kosavisit[v]) kosajaru3(v, r); }
vector<int> adjscc[maxn]; int aristas[maxn]; void kosajaru (void) {
    forf(u,0,n) if (!kosavisit[u]) kosajaru1(u);
    kosajaru2(); memset(kosavisit, 0, maxn*sizeof(int));
    for (int u : kosaorder) if(!kosavisit[u]) { kosacomp.push_back({}); kosajaru3(u, u); }
    memset(aristas, -1, sizeof(aristas));
    for (auto comp : kosacomp) for (int u : comp) for (int v : adj[u]) {
        int ru = kosaroot[u], rv = kosaroot[v];
        if (ru != rv && aristas[rv] != ru) aristas[rv] = ru, adjscc[ru].push_back(rv);
    }
}