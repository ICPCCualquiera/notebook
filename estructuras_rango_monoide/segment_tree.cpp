template<class T> struct SegTree {
    vector<T>& arr; int N; T id;
    T op (T a, T b) { return 0; } // !
    vector<T> t;
    void make () {
        t.resize(N << 1); rep(i,N) t[i+N] = arr[i];
        for (int i = N - 1; i; i--) t[i] = op(t[i<<1], t[i<<1|1]);
    }
    void set (int i, T v) {
        for(t[i += N] = v; i > 1; i >>= 1) t[i>>1] = op(t[i], t[i^1]);
    }
    T q (int l, int r) {
        T res = id;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = op(res, t[l++]);
            if (r&1) res = op(res, t[--r]);
        } return res;
    }
};