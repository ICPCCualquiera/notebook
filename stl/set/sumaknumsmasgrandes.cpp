struct SumaKNumsMasGrandes {
    ll k = 0 / 0, sum = 0 / 0;
    priority_queue<ll, vector<ll>, greater<ll>> minheap;
    void insertar (ll x) {
        if (sz(minheap) < k) {
            __insertar(x);
            return;
        }
        ll m = minheap.top();
        if (m < x) {
            minheap.pop();
            sum -= m;
            __insertar(x);
        }
    }
    void __insertar (ll x) {
        minheap.push(x);
        sum += x;
    }
};