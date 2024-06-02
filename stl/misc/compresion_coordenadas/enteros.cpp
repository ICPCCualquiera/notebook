// Obtener valor original con D[A[i]]
vector<ll> CompCoordenadas (vector<ll>& A) {
   int N = A.size();
   vector<ll> D = A;
   sort(all(D));
   D.resize(unique(all(D)) - D.begin());
   forn(i, N) A[i] = lower_bound(all(D), A[i]) - D.begin();
   return D;
}