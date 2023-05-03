Robadísimo de [El Diego](https://github.com/vmartinv/eldiego)
=======
```
make notebook-largo.pdf
make notebook-corto.pdf
make clean
```

TODO:
+ Agregar sub-secciones STL:
  + set (buscar elemento en un set)
  + policy based data structures
  + priority_queue (comparador custom)
+ Pasar segment tree a iterativo
+ Aclarar cómo se usa DSU
+ Búsqueda binaria
  + Usar operaciones de bits
  + Simplificar asumiendo que `pred[i] = true` y `pred[j] = false`
  + Aclarar cómo se usa
+ Refactor criba
+ Pasar LCA a iterativo
+ Agregar operaciones de bits a Misc.
+ Crear sección brainstorming
```
template <typename T>
T setleft (set<T>& s, T x, T def) {
    if (s.empty() || *s.begin() >= x) return def;
    if (*--s.end() < x) return *--s.end();
    return *--s.lower_bound(x);
}

template <typename T>
T setright (set<T>& s, T x, T def) {
    if (s.empty() || *--s.end() <= x) return def;
    if (*s.begin() > x) return *s.begin();
    return *s.upper_bound(x);
}
```