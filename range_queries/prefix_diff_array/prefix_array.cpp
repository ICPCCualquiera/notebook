#pragma region // prefix_array
templT vector<T> prefix_array_crear (vector<T>& A) {
    vector<T> P(sz(A));
    P[0] = A[0];
    forn(i, sz(P) - 1) P[i+1] = P[i] + A[i+1];
    return P;
}

templT T prefix_array_query (vector<T>& P, int i, int j) {
    T res = P[j];
    if (i > 0) res -= P[i-1];
    return res;
}
#pragma endregion