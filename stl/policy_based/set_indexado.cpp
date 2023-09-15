#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace  __gnu_pbds;

templT struct SetIndexado {
    tree<
        T, null_type, less<T>,
        rb_tree_tag, tree_order_statistics_node_update
    > s;
    void add  (T   x) { s.insert(x); }
    int  idx  (T   x) { return  s.order_of_key(x); }
    bool has  (T   x) { return  s.find(x) != ms.end(); }
    T    ith  (int i) { return *s.find_by_order(i); }
};
