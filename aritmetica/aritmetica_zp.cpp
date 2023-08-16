const i64 mod = 1e9 + 7;

i64 resta_mod (i64 a, i64 b) { return (a - b + mod) % mod; }

i64 pow_mod (i64 x, i64 n) {
    i64 res = 0;
    while (n) {
        if (n % 2) res = res * x % mod;
        n /= 2;
        x = x * x % mod;
    } return res;
}

i64 div_mod (i64 a, i64 b) { return a * pow_mod(b, mod - 2) % mod; }

