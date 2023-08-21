vector<i64> derivada (vector<i64>& A) {
    vector<i64> D(A.size());
    forn(i, A.size() - 1) D[i] = A[i+1] - A[i];
    return D;
}

void derivada_range_update (vector<i64>& D, int i, int j, i64 v) {
    D[i-1] += v;
    D[j]   -= v;
}

vector<i64> integral (vector<i64>& A) {
    vector<i64> I(A.size() + 1);
    I[0] = 0;
    forn(i, A.size()) I[i+1] = I[i] + A[i];
    return I;
}

i64 integral_range_query (vector<i64>& I, int i, int j) {
    return I[j+1] - I[i];
}