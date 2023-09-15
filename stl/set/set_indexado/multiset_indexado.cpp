#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace  __gnu_pbds;

templT struct MultisetIndexado {
    int t = 0; tree<
        pair<T, int>, null_type, less<pair<T, int>>,
        rb_tree_tag, tree_order_statistics_node_update
    > ms;
    void add  (T   x) { ms.insert(mp(x, t++)); }
    int  nle  (T   x) { return ms.order_of_key(mp(x, -1)); }
    int  nleq (T   x) { return ms.order_of_key(mp(x, INT_MAX)); }
    int  cnt  (T   x) { return nleq(x) - nle(x); }
    T    ith  (int i) { return (*ms.find_by_order(i)).fst; }
};