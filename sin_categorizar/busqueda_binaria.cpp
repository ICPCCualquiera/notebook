int primer_true (int i, int j, function<bool(int)> P, int def) {
   while (j - i > 1) {
      int m = i + ((j - i) >> 1);
      P(m) ? j = m : i = m;
   }
   if (P(i)) return i;
   if (P(j)) return j;
   return def;
}

int ultimo_false (int i, int j, function<bool(int)> P, int def) {
   while (j - i > 1) {
      int m = i + ((j - i) >> 1);
      P(m) ? j = m : i = m;
   }
   if (!P(j)) return j;
   if (!P(i)) return i;
   return def;
}