#pragma region // Segtree max query
struct SegtreeRMQ {
    vector<int> tree;
    int get (int i) { return tree[i + sz(tree) / 2]; }
    void update (int i, int x) {
        for (tree[i += sz(tree) / 2] = x; i > 1; i /= 2)
            tree[i / 2] = max(tree[i], tree[i ^ 1]);
    }
    int query (int i, int j) {
        int res = INT_MIN;
        int l = i + sz(tree) / 2;
        int r = j + sz(tree) / 2 + 1;
        for (; l < r; l /= 2, r /= 2) {
            if (l & 1) res = max(res, tree[l++]);
            if (r & 1) res = max(res, tree[--r]);
        } return res;
    }
};

auto SegtreeRMQ_crear (vector<int>& A) {
    vector<int> tree(2 * sz(A), INT_MIN);
    forn(i, sz(A)) tree[i + sz(A)] = A[i];
    for (int i = sz(A) - 1; i; i--) tree[i] = max(tree[2*i], tree[2*i + 1]);
    return SegtreeRMQ { tree };
}
#pragma endregion