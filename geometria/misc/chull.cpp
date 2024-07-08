vector<Punto> convex_hull (vector<Punto>& puntos, bool incluir_colineales = false) {
    vector<Punto> P = puntos;

    Punto p0 = *min_element(all(P), [](Punto a, Punto b) { return mt(a.y, a.x) < mt(b.y, b.x); });

    auto orientation = [&](const Punto& a, const Punto& b, const Punto& c) {
        Sca area = (b - a) ^ (c - b);
        if (sca_le(area, 0)) return -1;
        if (sca_le(0, area)) return +1;
        return 0;
    };

    sort(all(P), [&](const Punto& a, const Punto& b) {
        int o = orientacion(p0, a, b);
        if (o == 0) return sca_le(dist2(p0, a), dist2(p0, b));
        return o < 0;
    });

    if (incluir_colineales) {
        int i = sz(P) - 1;
        while (i >= 0 && orientacion(p0, P[i], P.back()) == 0) i--;
        reverse(P.begin() + i + 1, P.end());
    }

    vector<Punto> res;
    forn(i, sz(P)) {
        while (sz(res) > 1) {
            int o = orientacion(res[sz(res) - 2], res.back(), P[i]);
            if (o < 0 || (incluir_colineales && o == 0)) break;
            res.pop_back();
        }
        res.pb(P[i]);
    }
    if (!incluir_colineales && sz(res) == 2 && res[0] == res[1]) res.pop_back();

    return res;
}