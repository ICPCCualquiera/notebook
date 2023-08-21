vector<int> make_diff_array (vector<int>& A) {
    vector<int> D(A.size() - 1);
    forn(i, A.size() - 1) D[i] = A[i+1] - A[i];
    return D;
}

void diff_array_range_update (vector<int>& D, int i, int j, int v) {
    D[i-1] += v;
    D[j]   -= v;
}

vector<int> make_prefix_array (vector<int>& A) {
    vector<int> P(A.size() + 1);
    P[0] = 0;
    forn(i, A.size()) P[i+1] = P[i] + A[i];
    return P;
}

int prefix_array_range_query (vector<int>& P, int i, int j) {
    return P[j+1] - P[i];
}