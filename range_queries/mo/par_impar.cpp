bool mosort_parimpar (Query& p, Query& q) {
    if (p.i / MOSIZE != q.i / MOSIZE) return mosort(p, q);
    return (p.i / MOSIZE & 1) ? (p.j < q.j) : (p.j > q.j);
}