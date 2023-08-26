// Operacion asociativa IDEMPOTENTE

#define log2fl(x) (x ? 63 - __builtin_clzll(x) : -1)

struct STable {
    vector<int>& arr; int N;
    vector<vector<int>> st;
    // Modificar operacion
    int op (int a, int b) { return min(a,b); }
    void make () {
        st.resize(20, vector<int>(N));
        st[0] = arr; scn(w,1,19) scn(i,0,N - (1 << w))
            st[w][i] = op(st[w-1][i], st[w-1][i + (1 << (w-1))]);
    }
    int q (int i, int j) {
        int w = log2fl(j - i + 1);
        return op(st[w][i], st[w][j - (1 << w) + 1]);
    }
};

// Usar asi:
vector<int> A = {...};

STable stable = {A, A.size()};
stable.make();
