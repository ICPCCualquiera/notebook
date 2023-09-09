// Usa compresion de coordenadas y segtree point set (range maximum query)
int LIS (vector<int>& A) {
   int N = A.size();
   auto C = Compress(A);
 
   vector<STNode> hojas(N, {0});
   STree dp = segtree_build(hojas);
 
   segtree_update(dp, C[A[0]], {1});
   forr(i, 1, N) {
      int x = C[A[i]];
      int subres = 0;
      if (x-1 >= 0) subres = segtree_query(dp, 0, x-1).val;
      segtree_update(dp, x, {1 + subres});
   }
 
   return segtree_query(dp, 0, N - 1).val;
}