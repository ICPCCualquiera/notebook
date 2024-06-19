#pragma region // Fenwick
using Fenwick = unordered_map<int, ll>;
ll FT_prefix (Fenwick& A, int i) {
    ll res = 0;
    for (int j = i; j >= 0; j = j & (j + 1), j--) res += A[j];
    return res;
}
void FT_update (Fenwick& A, int N, int i, ll x) {
    for (; i < N; i = i | (i + 1)) A[i] += x;
}
ll FT_get (Fenwick& A, int i) {
    return FT_prefix(A, i);
}
void FT_add (Fenwick& A, int N, int i, int j, ll x) {
    FT_update(A, N, i, x);
    FT_update(A, N, j+1, -x);
}
#pragma endregion