
struct Query {
    int idx, i, j;
    ll ord;
};

const int MOSIZE = 0 / 0; // ~sqrt(n) (entre 150 y 800)

ll hilbertorder(ll x, ll y) {
    const ll logn = __lg(max(x, y) * 2 + 1) | 1;
    const ll maxn = (1ll << logn) - 1;
    ll res = 0;
    for (ll s = 1ll << (logn - 1); s; s >>= 1) {
        bool rx = x & s, ry = y & s;
        res = (res << 2) | (rx ? ry ? 2 : 1 : ry ? 3 : 0);
        if (!rx) {
            if (ry) x ^= maxn, y ^= maxn;
            swap(x, y);
        }
    }
    return res;
}

vector<int> mosolve (vector<Query>& queries, vector<int>& A) {
    for (auto q : queries) q.ord = hilbertorder(q.i, q.j);
    sort(all(queries), [](const Query& p, const Query& q) -> bool { return p.ord < q.ord; });
    vector<int> res(queries.size());
    // Inicializar estructura
    Query a = { -1, 0, -1 };
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