// Siempre hacer resize al final asi:

vector<int> A = { 5, 10, 15, 20, 25};
vector<int> B = {10, 20, 30, 40, 50};

vector<int> U(A.size() + B.size());

auto it = set_union(all(A), all(B), begin(U));

U.resize(it - U.begin());