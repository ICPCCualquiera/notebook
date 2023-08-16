template<class T>
vector<i64> prefix_table_rqpu (vector<T>& arr) {
    vector<i64> ps(arr.size() + 1);
    ps[0] = 0;
    rep(i,arr.size()) ps[i+1] = ps[i] + arr[i];
    return ps;
}

i64  prefix_table_range_query  (vector<i64>&ps, int i, int j) {
    return ps[++j] - ps[i];
}

void prefix_table_point_update (vector<i64>&ps, int i, int v) {
    scn(k, i, ps.size() - 1) ps[k] += v;
}