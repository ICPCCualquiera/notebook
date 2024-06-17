vector<Punto> intersect_circulo_circulo (Circulo o1, Circulo o2) {
    // Mismo origen, distinto radio -> cero puntos
    // Mismo origen, mismo radio    -> infinitos puntos
    Circulo o = {{o2.p - o1.p}, o2.r};
    Sca x = o.p.x, y = o.p.y;
    auto res = intersect_circulo_recta(o1.r, -2*x, -2*y, x*x + y*y + o1.r*o1.r - o.r*o.r);
    forn(i, res.size()) res[i] = res[i] + o1.p;
    return res;
}