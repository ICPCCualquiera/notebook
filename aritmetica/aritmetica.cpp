#define ceildiv(a,b) ((a+b-1)/b)

i64 isqrt (i64 x) {
    i64 s = 0; for (i64 k = 1 << 30; k; k >>= 1)
        if ((s+k)*(s+k) <= x) s += k;
    return s;
}

#define log2fl(x) (x ? 63 - __builtin_clzll(x) : -1)