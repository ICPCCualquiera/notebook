vector<Punto> intersect_circ_recta (Sca r, Sca a, Sca b, Sca c) {
    Sca z = a*a + b*b;
    Punto p = {-a*c / z, -b*c / z};
    if (flt_le(r*r*z, c*c)) return {};
    if (flt_eq(r*r*z, c*c)) return {p};
    Sca m = sqrtl((r*r - c*c / z) / z);
    Punto d1 = { b*m, -a*m }, d2 = { -b*m,  a*m };
    return { p + d1, p + d2 };
}