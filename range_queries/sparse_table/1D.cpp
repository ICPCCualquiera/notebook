#pragma region // SparseTable
using SparseTable = vector<vector<int>>;
SparseTable SparseTable_crear (vector<int>& A) {
    SparseTable res(20, vector<int>(sz(A)));
    res[0] = A;
    forr(w, 1, 20) forn(i, sz(A) - (1 << w) + 1)
        res[w][i] = min(res[w-1][i], res[w-1][i + (1 << (w - 1))]);
    return res;
}
int SparseTable_query (SparseTable& S, int i, int j) {
    int w = 63 - __builtin_clzll(j - i + 1);
    return min(S[w][i], S[w][j - (1 << w) + 1]);
}
#pragma endregion