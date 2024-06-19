#pragma region // ArrayEnlazado
struct ArrayEnlazado {
    map<int, set<int>> ocurrencias; // ocurrencias[x] := { i | arr[i] = x }
    vector<int> arr;
    vector<int> prevA; // prevA[i] := max j tq. j < i && arr[j] = arr[i] (def.  -1)
    vector<int> nextA; // nextA[i] := min j tq. i < j && arr[i] = arr[j] (def. sz(arr))
    void quitar (int i) {
        int x = arr[i];
        int ia = prevA[i], ib = nextA[i];
        if (ia !=         -1) nextA[ia] = ib;
        if (ib !=    sz(arr)) prevA[ib] = ia;
        ocurrencias[x].erase(i);
        prevA[i] = -1, nextA[i] = sz(arr);
    }
    void agregar (int i, int x) {
        arr[i] = x;
        if (ocurrencias[x].empty()) { ocurrencias[x].insert(i); return; }
        int m = *ocurrencias[x].begin(), M = *ocurrencias[x].rbegin();
        ocurrencias[x].insert(i);
        if (m < i) {
            int ia = *prev(ocurrencias[x].lower_bound(i));
            nextA[ia] =  i;
            prevA[ i] = ia;
        }
        if (i < M) {
            int ib = *ocurrencias[x].upper_bound(i);
            prevA[ib] =  i;
            nextA[ i] = ib;
        }
    }
    void update (int i, int x) { quitar(i); agregar(i, x); }
};

auto ArrayEnlazado_crear (vector<int>& A) {
    auto arr = A;
    vector<int> prevA(sz(A), -1);
    vector<int> nextA(sz(A), sz(A));
    ArrayEnlazado AE = {{}, arr, prevA, nextA};
    forn(i, sz(A)) AE.agregar(i, A[i]);
    return AE;
}
#pragma endregion