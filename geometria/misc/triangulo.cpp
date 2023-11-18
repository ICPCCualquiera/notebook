Sca area_triang (vector<Punto> T) { return abs((T[2] - T[1]) ^ (T[1] - T[0])) / 2; }

bool es_isosceles (vector<Punto> T) {
   forn(i, 3) {
      Punto a = T[i], b = T[(i+1)%3], c = T[(i+2)%3];
      if (sca_eq(dist2(a,b), dist2(b,c))) return true;
   } return false;
}