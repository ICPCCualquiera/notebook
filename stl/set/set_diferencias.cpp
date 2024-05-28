struct SetDiferencias {
    map<int, int> S;
    map<int, int> D;
    void insertar (int x) {
        if (S.empty()) {
            S[x]++;
            return;
        }
        int m = (*S.begin()).fst;
        int M = (*S.rbegin()).fst;
        int a, b;
        if (S.count(x)) D[0]++;
        S[x]++;
        if (x < M) {
            b = (*(S.upper_bound(x))).fst;
            D[b - x]++;
        }
        if (m < x) {
            a = (*(prev(S.lower_bound(x)))).fst;
            D[x - a]++;
        }
        if (m < x && x < M) {
            D[b - a]--; if (D[b - a] <= 0) D.erase(b - a);
        }
    }
    void eliminar (int x) {
        int m = (*S.begin()).fst;
        int M = (*S.rbegin()).fst;
        int a, b;
        if (x < M) {
            b = (*(S.upper_bound(x))).fst;
            D[b - x]--; if (D[b - x] <= 0) D.erase(b - x);
        }
        if (m < x) {
            a = (*(prev(S.lower_bound(x)))).fst;
            D[x - a]--; if (D[x - a] <= 0) D.erase(x - a);
        }
        if (m < x && x < M) {
            D[b - a]++;
        }
        if (S.count(x) && S[x] > 1) D[0]--;
        if (D[0] == 0) D.erase(0);
        S[x]--; if (S[x] <= 0) S.erase(x);
    }
    int max_diferencia () {
        return (*D.rbegin()).fst;
    }
    int min_diferencia () {
        return (*D.begin()).fst;
    }
};