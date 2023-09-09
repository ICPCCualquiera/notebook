struct Hedge { ll weight; int node; };
bool operator < (const Hedge& a, const Hedge& b) { return a.weight > b.weight; }
using AdjList = vector<vector<Hedge>>;

void Dijkstra (AdjList& G, int s, vector<ll>& dist, vector<int>& parent) {
   int N = G.size();
   dist.assign(N, LLONG_MAX);
   dist[s] = 0;
   parent.assign(N, -1);
   parent[s] = s;
   priority_queue<Hedge> bag;
   for (bag.push({0, s}); bag.size();) {
      auto [d, u] = bag.top();
      bag.pop();
      if (d > dist[u]) continue;
      for (auto [w, v] : G[u]) {
         ll relax = d + w;
         if (relax < dist[v]) {
            dist[v] = relax;
            parent[v] = u;
            bag.push({relax, v});
         }
      }
   }
}