Robadísimo de [El Diego](https://github.com/vmartinv/eldiego)
=======
```
make notebook.pdf
make clean
```

TODO:
+ STL:
  + lower_bound / upper_bound
  + multiset
  + order statistics set (no multiset)
  + renombralo a "indexed set"
  + priority_queue con comparador custom
  + __gnu_pbds trie con búsqueda por prefix range (https://ideone.com/6VFNZl)
+ Math: pow mod n
+ Algoritmos:
  + parallel binary search
  + Mo
+ Operaciones comunes:
  + RMQ
  + Valor más frequente
  + Range add point query
+ Estructuras genéricas:
  + linked list
  + FT
+ Grafos:
  + Subtree queries -> range queries
  + SCC y grafo condensado
  + maximum matching
+ Nueva seccion: brainstorming?
+ Reescribir estructuras para aceptar tipos genéricos así:

```C++
// Valor
struct Val {
  i64 val;
  inline Val operator+(const Val& x) const {
    return {val + x.val};
  }
}
// Lazy update: setear valor a setv y luego sumar addv
struct Upd {
  bool set;
  i64 setv, addv;
  inline Upd operator*(const Upd& op) const {
    if (op.set) return op;
    else return {set, setv, addv + op.addv};
  }
};
// Aplicar update a valor
Val operator*(const Upd& op, const Val& x) {
  Val res = val; // Problema con referencia?
  if (op.set) res.val = op.setv;
  res.val += op.addv;
  return res;
}
```
