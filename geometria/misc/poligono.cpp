Sca area_poli (vector<Punto> P) {
    Sca res = 0;
    forn(i, P.size()) {
        Punto p = i ? P[i - 1] : P.back();
        res += (p.x - P[i].x) * (p.y + P[i].y);
    } return abs(res) / 2;
}