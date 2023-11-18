Punto intersect_recta (Punto p1, Punto d1, Punto p2, Punto d2) {
    // d1 ^ d2 == 0 ?
    return p1 + d1 * ((p2 - p1) ^ d1) / (d1 ^ d2);
}