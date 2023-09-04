using AdjList = vector<vector<int>>;
using Edge = pair<int, int>;

vector<Edge> GetPuentes (AdjList& G) {
   int N = G.size(), time;
   vector<bool> visitado(N, false);
   vector<int> tin(N, -1), tlow(N, -1);
   vector<Edge> res;
   function<void(int, int)> dfs = [&](int u, int p) -> void {
      visitado[u] = true;
      tin[u] = tlow[u] = time++;
      for (int v : G[u]) {
         if (v == p) continue;
         if (visitado[v]) tlow[u] = min(tlow[u], tin[v]);
         else {
            dfs(v, u);
            tlow[u] = min(tlow[u], tlow[v]);
            if (tlow[v] > tin[u]) res.pb({u,v});
         }
      }
   };
   forn(r, N) if (!visitado[r]) {
      time = 0; 
      dfs(r, -1);
   }
   return res;
}