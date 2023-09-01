templT vector<T> diff_array (vector<T>& A) {
    vector<T> D(A.size());
    D[0] = A[0];
    forn(i, D.size() - 1) D[i+1] = A[i+1] - A[i];
    return D;
}

// Aplica +x en A[i] ... A[j] 
templT void update_diff_array (vector<T>& D, int i, unsigned j, T x) {
    D[i] += x;
    if (j + 1 < D.size()) D[j+1] -= x;
}

templT vector<T> prefix_array (vector<T>& A) {
    vector<T> P(A.size());
    P[0] = A[0];
    forn(i, P.size() - 1) P[i+1] = P[i] + A[i+1];
    return P;
}

// Retorna A[i] + ... +  A[j]
templT T query_prefix_array (vector<T>& P, int i, int j) {
    T res = P[j];
    if (i > 0) res -= P[i-1];
    return res;
}
 