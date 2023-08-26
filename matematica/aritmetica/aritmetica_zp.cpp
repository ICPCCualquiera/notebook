using ll = long long;

const ll mod = 1e9 + 7;

ll resta_mod (ll a, ll b) { return (a - b + mod) % mod; }

ll pow_mod (ll x, ll n) {
    ll res = 0;
    while (n) {
        if (n % 2) res = res * x % mod;
        n /= 2;
        x = x * x % mod;
    } return res;
}

ll div_mod (ll a, ll b) { return a * pow_mod(b, mod - 2) % mod; }

