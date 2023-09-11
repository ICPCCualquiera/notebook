struct STNode { int len, idx, val, parent; };
bool operator < (STNode a, STNode b) {
   if (a.len != b.len) return a.len < b.len;
   return a.val > b.val;
}
STNode operator * (STNode a, STNode b) { return max(a,b); }
const STNode ST_ID = { -INT_MAX, -1, INT_MAX, -1 };

vector<int> LIS (vector<int>& A) {
   int N = A.size();
   auto C = Compress(A);

   STNode def = {0, -1, INT_MAX, -1};
   vector<STNode> hojas(N, def);
   STree dp = segtree_build(hojas);

   vector<STNode> res(N);
   res[0] = {1, 0, A[0], -1};
   segtree_update(dp, C[A[0]], {1, 0, A[0], -1});
   forr(i, 1, N) {
      int x = C[A[i]];
      STNode subres = def;
      if (x-1 >= 0) subres = segtree_query(dp, 0, x-1);
      STNode r = {1 + subres.len, i, A[i], subres.idx};
      segtree_update(dp, x, r);
      res[i] = r;
   }

   vector<int> path;
   STNode best = *max_element(all(res));
   STNode x;
   for (x = best; x.parent != -1; x = res[x.parent]) path.pb(x.idx);
   path.pb(x.idx);
   reverse(all(path));

   return path;
}