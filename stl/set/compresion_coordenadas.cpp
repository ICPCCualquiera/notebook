templT map<T, int> compress (vector<T>& A) {
   map<T, int> ord;
   int n = 0;
   for (auto  v :  A)  ord[v];
   for (auto& e : ord) e.snd = n++;
   return ord;
}