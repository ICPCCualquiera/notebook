vector<Punto> intersect_circ_circ (Circ o1, Circ o2) {
    // Mismo origen, distinto radio -> cero puntos
    // Mismo origen, mismo radio    -> infinitos puntos
    Circ o = {{o2.p - o1.p}, o2.r};
    Sca x = o.p.x, y = o.p.y;
    auto res = intersect_circ_recta(o1.r, -2*x, -2*y, x*x + y*y + o1.r*o1.r - o.r*o.r);
    forn(i, res.size()) res[i] = res[i] + o1.p;
    return res;
}