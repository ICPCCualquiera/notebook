int es_compuesto[maxn]; vector<int> primos;
void criba (int n) {
    forf(i,2,n) if (!es_compuesto[i]) {
        primos.push_back(i); for (int j = 2; i*j < n; j++) es_compuesto[i*j] = 1;
    }
}