#pragma region // template geometria
// const bool USO_FLOAT = false; using Sca = ll;
bool sca_le  (Sca a, Sca b) { return USO_FLOAT ? flt_le(a, b) : a <  b; }
bool sca_eq  (Sca a, Sca b) { return USO_FLOAT ? flt_eq(a, b) : a == b; }
bool sca_leq (Sca a, Sca b) { return sca_le(a, b) || sca_eq(a, b); }
struct Punto { Sca x, y; };
Punto operator  * (Punto p, Sca   a) { return {p.x * a, p.y * a}; }
Punto operator  + (Punto p, Punto q) { return {p.x + q.x, p.y + q.y}; }
Sca   operator  * (Punto p, Punto q) { return p.x * q.x + p.y * q.y; } // |p| |q| cos theta
Sca   operator  ^ (Punto p, Punto q) { return p.x * q.y - p.y * q.x; } // |p| |q| sin theta
Punto operator  - (Punto p, Punto q) { return p + (q * -1); }
Punto operator  / (Punto p, Sca   a) { return {p.x / a, p.y / a}; }
Sca   proj        (Punto p, Punto q) { return p * q / sqrtl(q * q); }
Sca   angulo      (Punto p, Punto q) { return acos(p * q / sqrtl(p*p) / sqrtl(q*q)); }
Sca   dist2       (Punto p, Punto q) { return (p - q) * (p - q); }
Sca   dist        (Punto p, Punto q) { return sqrtl(dist2(p, q)); }
bool  operator == (Punto p, Punto q) { return  sca_eq(p.x, q.x) &&  sca_eq(p.y, q.y); }
bool  operator  < (Punto p, Punto q) { return sca_eq(p.y, q.y) ? sca_le(p.x, q.x) : sca_le(p.y, q.y); }
ostream& operator << (ostream &o, Punto& p) { return o << "(" << p.x << ", " << p.y << ")"; }
#pragma endregion