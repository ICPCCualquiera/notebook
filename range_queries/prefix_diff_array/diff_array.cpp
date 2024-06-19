#pragma region // diff_array
templT vector<T> diff_array_crear (vector<T>& A) {
    vector<T> D(sz(A));
    D[0] = A[0];
    forn(i, sz(D) - 1) D[i+1] = A[i+1] - A[i];
    return D;
}

// Aplica +x en A[i] ... A[j] 
templT void diff_array_incrementar (vector<T>& D, int i, int j, T x) {
    D[i] += x;
    if (j + 1 < sz(D)) D[j+1] -= x;
}
#pragma endregion