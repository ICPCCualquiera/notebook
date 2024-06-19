struct Multiset {
    map<int, int> ocurrencias;
    void insertar (int x) { ocurrencias[x]++; }
    void eliminar (int x) {
        auto it = ocurrencias.find(x);
        assert(it != ocurrencias.end());
        if (--it->snd == 0) ocurrencias.erase(it);
    }
    int count (int x) {
        auto it = ocurrencias.find(x);
        return it == ocurrencias.end() ? 0 : it->snd;
    }
    int min (void) {
        assert(ocurrencias.size());
        return ocurrencias.begin()->fst;
    }
    int max (void) {
        assert(ocurrencias.size());
        return ocurrencias.rbegin()->fst;
    }
    int primer_mayor (int x) {
        assert(x < max());
        return ocurrencias.upper_bound(x)->fst;
    }
    int primer_menor (int x) {
        assert(min() < x);
        return prev(ocurrencias.lower_bound(x))->fst;
    }
};