template<class T>
vector<i64> prefix_table_rupq (vector<T>& arr) {
    vector<i64> ps(arr.size() + 1);
    rep(i,arr.size()) ps[i] += arr[i], ps[i+1] -= arr[i];
    return ps;
}

void prefix_table_range_update (vector<i64>&ps, int i, int j, int v) {
    ps[i] += v, ps[++j] -= v;
}

vecor<i64> prefix_table_rupq_rebuild (vector<i64>&ps) {
    vector<i64> arr(ps.size() - 1);
    arr[0] = ps[0];
    rep(i, arr.size() - 1) arr[i+1] = arr[i] + ps[i+1];
    return arr;
}

i64  prefix_table_point_query  (vector<i64>&ps, int i) {
    i64 res = 0;
    rep(k, i + 1) res += ps[k];
    return res;
}