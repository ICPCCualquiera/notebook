struct Circ { Punto p; Sca r; };
bool operator == (Circ o1, Circ o2) { return o1.p == o2.p && sca_eq(o1.r, o2.r); }
