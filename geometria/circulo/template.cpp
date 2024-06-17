#pragma region // circulo
struct Circulo { Punto p; Sca r; };
bool operator == (Circulo o1, Circulo o2) { return o1.p == o2.p && sca_eq(o1.r, o2.r); }
bool contiene (Circulo& c, Punto& punto) { return sca_leq(dist2(c.p, punto), c.r*c.r); }
#pragma endregion