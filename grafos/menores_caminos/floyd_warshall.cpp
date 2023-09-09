templT using Matriz = vector<vector<T>>;
const ll INF = LLONG_MAX / 4;

void FloydWarshall (Matriz<ll>& D) {
   int N = D.size();
   forn(u, N) D[u][u] = 0;
   forn(k, N) forn(u, N) forn(v, N) if (D[u][k] < INF) if (D[k][v] < INF)
      D[u][v] = min(D[u][v], D[u][k] + D[k][v]);
   // Opcional: chequear ciclos negativos
   forn(u, N) forn(v, N) forn(k, N) if (D[u][k] < INF && D[k][k] < 0 && D[k][v] < INF)
      D[u][v] = -INF;
}