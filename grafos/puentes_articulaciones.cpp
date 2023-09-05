using AdjList = vector<vector<int>>;
using Edge = pair<int, int>;
pair<vector<Edge>, vector<int>> GetPuentesArticulaciones (AdjList& G) {
   int N = G.size(), time = 0;
   vector<bool> visitado(N);
   vector<int> tin(N, -1), tlow(N, -1), articulaciones;
   vector<Edge> puentes;
   function<void(int, int)> dfs = [&](int u, int p) -> void {
      visitado[u] = true;
      tin[u] = tlow[u] = time++;
      int hijos = 0;
      for (int v : G[u]) {
         if (v == p) continue;
         if (visitado[v]) tlow[u] = min(tlow[u], tin[v]);
         else {
            dfs(v, u);
            hijos++;
            tlow[u] = min(tlow[u], tlow[v]);
            if (tlow[v] >  tin[u]) puentes.pb({u,v});
            if (tlow[v] >= tin[u] && p != -1) articulaciones.pb(u);
         }
      }
      if (p == -1 && hijos > 1) articulaciones.pb(u);
   };
   forn(r, N) if (!visitado[r]) dfs(r, -1);
   return mp(puentes, articulaciones);
}