#pragma region // template geometria
using flt = long double;
const flt EPS = 1e-9;
bool  flt_le  (flt a, flt b) { return a + EPS < b; }
bool  flt_eq  (flt a, flt b) { return -EPS <= a - b && a - b <= EPS; }
bool  flt_leq (flt a, flt b) { return flt_le(a, b) || flt_eq(a, b); }
#pragma endregion