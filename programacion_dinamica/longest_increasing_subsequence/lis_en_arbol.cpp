// Usa compresion de coordenadas y segtree point set RMQ (tomar el maximo)
using AdjList = vector<vector<int>>;
vector<int> LIS (AdjList& G, vector<int>& valor_nodo, int root = 0) {
   int N = valor_nodo.size();
   auto C = Compress(valor_nodo);
 
   STNode def = { 0 };
   vector<STNode> hojas(N, def);
   STree dp = segtree_build(hojas);
 
   vector<int> res(N);
 
   segtree_update(dp, C[valor_nodo[root]], {1});
   function<void(int)> dfs = [&](int u) {
      int x = C[valor_nodo[u]];
      int old = segtree_query(dp, x, x).val;
      int subres = {0};
      if (x-1 >= 0) subres = segtree_query(dp, 0, x-1).val;
      segtree_update(dp, x, {1 + subres});
      res[u] = segtree_query(dp, 0, N-1).val;
      for (int v : G[u]) dfs(v);
      segtree_update(dp, x, {old});
   };
   dfs(root);
 
   return res;
}