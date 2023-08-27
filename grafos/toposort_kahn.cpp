using AdjList = vector<vector<int>>;

using Bag = priority_queue<int, vector<int>, greater<int>>;

struct KahnToposort {
    int N;
    AdjList& G;
    vector<int>& indegree;
    vector<int> visit, res;
    vector<int> Run () {
        visit.resize(N);
        Bag bag;
        forn(u, N) if(indegree[u] == 0) bag.push(u);
        while (bag.size()) {
            int u = bag.top();
            bag.pop();
            res.push_back(u);
            for (int v : G[u]) {
                indegree[v]--;
                if (indegree[v] == 0) bag.push(v);
            }
        }
        return res;
    }
};

// Usar asi:
int N = ...;
AdjList G = {...};
vector<int> indegree(N);
forn(u, N) for (int v : G[u]) indegree[v]++;

KahnToposort kahntoposort = {N, G, indegree};
vector<int> topo_ord = kahntoposort.Run();