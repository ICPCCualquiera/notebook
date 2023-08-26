using flt = long double;
const flt EPS = 1e-9;
bool  flt_leq (flt a, flt b) { return a < b + EPS; }
bool  flt_eq  (flt a, flt b) { return -EPS <= a - b && a - b <= EPS; }

struct Vec {
    int x, y;
    Vec operator+(Vec p) { return {x + p.x, y + p.y}; }
    Vec operator-(Vec p) { return {x - p.x, y - p.y}; }
    int operator*(Vec p) { return x * p.x + y * p.y; }
    int operator^(Vec p) { return x * p.y + y * p.x; }
};

int norma2 (Vec p) { return p.x * p.x + p.y * p.y; }