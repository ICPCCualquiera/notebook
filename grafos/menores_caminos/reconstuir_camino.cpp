auto reconstuir_camino (vector<int>& padre, int destino) {
   vector<int> res = { destino };
   int u = destino;
   do { u = padre[u]; res.pb(u); } while (u != padre[u]);
   reverse(all(res));
   return res;
}