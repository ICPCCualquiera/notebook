// Obtener valor original con D[A[i]]
vector<ll> CompCoordenadas (vector<ll>& A) {
   vector<ll> D = A;
   sort(all(D));
   D.resize(unique(all(D)) - D.begin());
   forn(i, sz(A)) A[i] = lower_bound(all(D), A[i]) - D.begin();
   return D;
}