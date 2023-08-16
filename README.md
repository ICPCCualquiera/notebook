Robadísimo de [El Diego](https://github.com/vmartinv/eldiego)
=======
```
make notebook.pdf
make clean
```

Idea:
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
