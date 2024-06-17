vector<Punto> intersect_circulo_recta (Sca radio, Sca a, Sca b, Sca c) {
    // a, b, c := parametros recta general
    Sca z = a*a + b*b;
    Punto punto_mas_cercano_origen = {-a*c / z, -b*c / z};
    if (flt_le(radio*radio*z, c*c)) return {}; // dist_origen > radio
    if (flt_eq(radio*radio*z, c*c)) return {punto_mas_cercano_origen}; // dist_origen = radio
    Sca m = sqrtl((radio*radio - c*c / z) / z);
    Punto d1 = { b*m, -a*m }, d2 = { -b*m,  a*m };
    return { punto_mas_cercano_origen + d1, punto_mas_cercano_origen + d2 };
}