struct Query { int idx, i, j; };

const int MOSIZE = 0 / 0; // ~sqrt(n) (entre 150 y 800)

bool mosort (Query const& p, Query const& q) {
   int bp = p.i / MOSIZE, bq = q.i / MOSIZE;
   if (bp == bq) return bq % 2 ? p.j > q.j : p.j < q.j;
   return bp < bq;
}

vector<int> mosolve (vector<Query>& queries) {
    sort(all(queries), mosort);
    vector<int> res(sz(queries));
    // Inicializar estructura
    Query a = { -1, 0, -1 };
    for (auto q : queries) {
        while (a.i > q.i) {
            a.i--;
            assert(0); // Estructura.add(a.i)
        }
        while (a.j < q.j) {
            a.j++;
            assert(0); // Estructura.add(a.j)
        }
        while (a.i < q.i) {
            assert(0); // Estructura.erase(a.i)
            a.i++;
        }
        while (a.j > q.j) {
            assert(0); // Estructura.erase(a.j)
            a.j--;
        }
        res[q.idx] = 0 / 0; // Resolver query
    }
    return res;
}