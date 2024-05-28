struct Query { int idx, i, j; };

const int MOSIZE = 0 / 0; // ~sqrt(n) (entre 150 y 800)

bool mosort (Query& p, Query& q) {
    if (p.i / MOSIZE == q.i / MOSIZE) return p.j < q.j;
    return p.i / MOSIZE < q.i / MOSIZE;
}

vector<int> mosolve (vector<Query>& queries) {
    sort(all(queries), mosort);
    vector<int> res(queries.size());
    // Inicializar estructura
    Query a = { -1, -1, -1 };
    for (auto q : queries) {
        while (a.i > q.i) {
            a.i--;
            // Estructura.add(a.i)
            assert(0);
        }
        while (a.j < q.j) {
            a.j++;
            // Estructura.add(a.j)
            assert(0);
        }
        while (a.i < q.i) {
            // Estructura.erase(a.i)
            assert(0);
            a.i++;
        }
        while (a.j > q.j) {
            // Estructura.erase(a.j)
            assert(0);
            a.j--;
        }
        res[q.idx] = 0 / 0; // Resolver query
    }
    return res;
}