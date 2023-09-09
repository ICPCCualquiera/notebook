struct STNode { int val; };
STNode operator * (STNode a, STNode b) { return (a.val < b.val) ? a : b; }
const STNode ST_ID = { INT_MAX };

vector<int> A = { ... };
vector<STNode> hojas(A.size());
transform(all(A), begin(hojas), [](int x) { return (STNode){x}; });
STree T = segtree_build(hojas);