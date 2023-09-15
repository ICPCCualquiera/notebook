using FT = ll;
using Fenwick = unordered_map<int, FT>;
FT FT_prefix (Fenwick& A, int i) {
    FT res = 0;
    for (int j = i; j >= 0; j = j & (j + 1), j--) res += A[j];
    return res;
}
void FT_add (Fenwick& A, int N, int i, FT x) {
    for (; i < N; i = i | (i + 1)) A[i] += x;
}
FT FT_sum (Fenwick& A, int i, int j) {
    return FT_prefix(A, j) - FT_prefix(A, i - 1);
}
void FT_set (Fenwick& A, int N, int i, FT x) {
    FT_add(A, N, i, - FT_sum(A, i, i));
    FT_add(A, N, i, + x);
}