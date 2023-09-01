// Operacion asociativa IDEMPOTENTE

#define log2fl(x) (x ? 63 - __builtin_clzll(x) : -1)

templT struct SparseTable {
    vector<T>& arr; int N;
    vector<vector<T>> st;
    // Modificar operacion
    T op (T a, T b) { return min(a,b); }
    void make () {
        st.resize(20, vector<T>(N));
        st[0] = arr; forn(w,19) forn(i,N - (1 << (w+1)) - 1)
            st[w+1][i] = op(st[w][i], st[w][i + (1 << w)]);
    }
    T query (int i, int j) {
        int w = log2fl(j - i + 1);
        return op(st[w][i], st[w][j - (1 << w) + 1]);
    }
};

// Usar asi:
vector<int> A = {...};

SparseTable<int> sparse_table = {A, A.size()};
sparse_table.make();
