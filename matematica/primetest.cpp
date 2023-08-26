struct Primetest {
    bool c[1000001]; vector<int> p;
    primetest () {
        p.reserve(1<<16); scn(i,2,1000000) if (!c[i]) {
            p.pb(i); for (int j = 2; i*j < 1000001; j++) c[i*j] = 1;
        }
    }
    bool isprime (int x) {
        for (int i = 0, d = p[i]; d*d <= x; d = p[++i])
            if (!(x % d)) return false;
        return x >= 2;
    }
};