const int MAXN = 1<<20; // ~1e6 

long long ST[2*MAXN];

long long querie(int nodo, int left, int right, int a, int b) {
    if (left >= b || right <= a) return 0;
    if (left >= a && right <= b) return ST[nodo];
    int m = (left + right) / 2;
    long long q1 = querie(nodo*2,left,m,a,b);
    long long q2 = querie(nodo*2+1,m,right,a,b);
    return q1 + q2;
}
void update(int p, long long val) {
    ST[p] = val;
    for (p = p/2; p > 0; p /= 2) ST[p] = op(ST[p*2], ST[p*2+1]);
}
