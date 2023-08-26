// Usar array indexado desde 1 con A[0] = 0
// Usar intervalos cerrado-cerrado (indexados desde 1)

using ll = long long;

vector<ll> derivada (vector<ll>& A) {
    vector<ll> D(A.size());
    forn(i, A.size() - 1) D[i] = A[i+1] - A[i];
    return D;
}

void derivada_range_update (vector<ll>& D, int i, int j, ll v) {
    D[i-1] += v;
    D[j]   -= v;
}

vector<ll> integral (vector<ll>& A) {
    vector<ll> I(A.size() + 1);
    I[0] = 0;
    forn(i, A.size()) I[i+1] = I[i] + A[i];
    return I;
}

ll integral_range_query (vector<ll>& I, int i, int j) {
    return I[j+1] - I[i];
}