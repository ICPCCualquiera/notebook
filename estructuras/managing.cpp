#include <bits/stdc++.h>
using namespace std;
#define endl         '\n'
#define forn(i,N)    for (int i = 0; i < int(N); i++)
#define all(v)       begin(v), end(v)
#define dbg(x)       cerr << #x << " = " << (x) << endl
#define raya         cerr << "================" << endl
#define forall(it,v) for (auto it = begin(v); it != end(v); it++)
#define printall(v)  forall(x,v) { cout << *x << " "; } cout << endl
#define printpair(p) cout << "(" << p.first << ", " << p.second << ")" << endl

struct BinaryTrieVertex { vector<int> next = {-1, -1}; };
using BinaryTrie = vector<BinaryTrieVertex>;
void binary_trie_add (BinaryTrie& trie, int x) {
    int v = 0;
    for (int i = 31; i >= 0; i--) {
        bool b = (x & (1 << i)) > 0;
        if (trie[v].next[b] == -1) {
            trie[v].next[b] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[b];
    }
}
int binary_trie_max_xor (BinaryTrie& trie, int x) {
    int v = 0, res = 0;
    for (int i = 31; i >= 0; i--) {
        bool b = (x & (1 << i)) > 0;
        if (trie[v].next[!b] != -1) {
            v = trie[v].next[!b];
            if (!b) res |= (1 << i);
        }
        else {
            v = trie[v].next[ b];
            if ( b) res |= (1 << i);
        }
    } return res;
}

const int MAXN = 2e5;
int N;
struct Hedge { int nodo, precio; };
vector<Hedge> adjlist[MAXN], hijos[MAXN];

bool rootear_visit[MAXN];
void rootear (int u) {
    rootear_visit[u] = 1;
    for (Hedge e : adjlist[u]) {
        int v = e.nodo;
        if (!rootear_visit[v]) {
            hijos[u].push_back({v,e.precio});
            rootear(v);
        }
    }
}

BinaryTrie trie(1);

int f[MAXN]; // f[u] := xor desde la raiz hasta u
void get_f (int u, int cumxor = 0) {
    f[u] = cumxor;
    binary_trie_add(trie, cumxor);
    for (Hedge e : hijos[u]) {
        get_f(e.nodo, e.precio ^ cumxor);
    }
}

int main (void) { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // leer input
    cin >> N;
    forn(i, N-1) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adjlist[a].push_back({b,c});
        adjlist[b].push_back({a,c});
    }

    rootear(0);
    get_f(0);

    forn(i, N) cout << (f[i] ^ binary_trie_max_xor(trie, f[i])) << endl;
    return 0;
}