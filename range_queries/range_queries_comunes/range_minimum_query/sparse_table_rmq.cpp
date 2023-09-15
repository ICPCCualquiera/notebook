using ST = int;
using SparseT = vector<vector<ST>>;
SparseT ST_build (vector<ST>& A, int N) {
    SparseT res(20, vector<ST>(N));
    res[0] = A;
    forr(w, 1, 20) forn(i, N - (1 << w) + 1)
        res[w][i] = min(res[w - 1][i], res[w - 1][i + (1 << (w - 1))]);
    return res;
}
ST ST_rmq (SparseT& S, int i, int j) {
    int w = 63 - __builtin_clzll(j - i + 1);
    return min(S[w][i], S[w][j - (1 << w) + 1]);
}