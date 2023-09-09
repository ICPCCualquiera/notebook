struct STNode {
   // Completar
};

STNode operator * (STNode a, STNode b) {
   // Completar
}

const STNode ST_ID = {
   // Completar
}
 
using STree = vector<STNode>;
STree segtree_build (STree& hojas) {
   int N = hojas.size();
   STree S(N << 1);
   forn(i, N) S[i + N] = hojas[i];
   for (int i = N - 1; i; i--) S[i] = S[i << 1] * S[i << 1 | 1];
   return S;
}
 
STNode segtree_query (STree& S, int i, int j) {
   int N = S.size() >> 1;
   STNode res = ST_ID;
   int l = i + N;
   int r = j + N + 1;
   for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res = res * S[l++];
      if (r & 1) res = res * S[--r];
   }
   return res;
}
 
void segtree_update (STree& S, int i, STNode x) {
   int N = S.size() >> 1;
   S[i += N] = x;
   for (; i > 1; i >>= 1) S[i >> 1] = S[i] * S[i ^ 1];
}