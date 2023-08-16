i64 bsearch (i64 i, i64 j, bool (*pred)(i64), i64 d) {
    while (!(i + 1 == j)) {
        i64 m = i + ((j - i) >> 1);
        pred(m) ? j = m : i = m;
    }
    if (pred(i)) return i;
    if (pred(j)) return j;
    return d;
}