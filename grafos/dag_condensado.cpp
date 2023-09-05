using AdjList = vector<vector<int>>;

AdjList DAGCondensado (AdjList& G) {
   int N = G.size();
   vector<bool> visitado(N);

   vector<int> orden;
   function<void(int)> get_orden = [&](int u) -> void {
      visitado[u] = true;
      for (int v : G[u]) if (!visitado[v]) get_orden(v);
      orden.pb(u);
   };
   forn(u, N) if (!visitado[u]) get_orden(u);
   reverse(all(orden));

   AdjList T(N);
   forn(u, N) for (int v : G[u]) T[v].pb(u);

   vector<int> comp, raiz(N), raices;
   function<void(int)> extraer_comp = [&](int u) -> void {
      visitado[u] = true;
      comp.pb(u);
      for (int v : T[u]) if (!visitado[v]) extraer_comp(v);
   };

   visitado.assign(N, false);
   for (int u : orden) if (!visitado[u]) {
      extraer_comp(u);
      int r = comp.front();
      for (int v : comp) raiz[v] = r;
      raices.pb(r);
      comp.clear();
   }

   int c = 0;
   map<int, int> coords;
   for (int   r :  raices) coords[r];
   for (auto& e : coords) e.snd = c++;

   AdjList SCC(raices.size());
   forn(u, N) for (int v : G[u]) {
      int ru = coords[raiz[u]], rv = coords[raiz[v]];
      if (ru != rv) SCC[ru].pb(rv);
   }

   return SCC;
}