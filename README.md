Robadísimo de [El Diego](https://github.com/vmartinv/eldiego)
=======
```
make notebook-largo.pdf
make notebook-corto.pdf
make clean
```

TODO:
+ STL:
  + order statistics tree
  + priority_queue con comparador custom
+ Matemática:
  + pow
  + criba, isprime O(sqrt(n)/log(n))
+ ST con lazy updates
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
