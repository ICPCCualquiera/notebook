using ll = long long;

// Si existe, el primer i donde pred(i) == true
// Si es todo false, devuelve d

ll bsearch (ll i, ll j, bool (*pred)(ll), ll d) {
    while (!(i + 1 == j)) {
        ll m = i + ((j - i) >> 1);
        pred(m) ? j = m : i = m;
    }
    if (pred(i)) return i;
    if (pred(j)) return j;
    return d;
}