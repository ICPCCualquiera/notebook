using flt = long double;
const flt EPS = 1e-9;
bool  flt_leq (flt a, flt b) { return a < b + EPS; }
bool  flt_eq  (flt a, flt b) { return -EPS <= a - b && a - b <= EPS; }

using Sca = long long;
struct Vec { Sca x, y; };
Vec  operator + (Vec a, Vec b) { return { a.x + b.x, a.y + b.y }; }
Vec  operator - (Vec a, Vec b) { return { a.x - b.x, a.y - b.y }; }
Sca  operator * (Vec a, Vec b) { return a.x * b.x + a.y * b.y; }
Sca  operator ^ (Vec a, Vec b) { return a.x * b.y + a.y * b.x; }
bool operator < (Vec a, Vec b) { return (a.x != b.x) ? (a.x < b.x) : (a.y < b.y); }
ostream& operator << (ostream &o, Vec& p) { auto x = mp(p.x, p.y); return o << x; }

Sca norma2 (Vec p) { return p.x * p.x + p.y * p.y; }