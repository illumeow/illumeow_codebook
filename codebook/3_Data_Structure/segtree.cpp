struct Seg {
  #define lc x<<1
  #define rc x<<1|1
  struct node {
    int data, tag;
  } seg[MAXN << 2]; // 1-based
  int n;
  void addtag(int x, int L, int R, int t) {
    seg[x].data += t * (R - L + 1);
    seg[x].tag += t;
  }
  void pull(int x) {
    seg[x].data = seg[lc].data + seg[rc].data;
  }
  void push(int x, int L, int R) {
    int M = (L + R) / 2;
    addtag(lc, L, M, seg[x].tag);
    addtag(rc, M + 1, R, seg[x].tag);
    seg[x].tag = 0;
  }
  void build(int x, int L, int R, vector<int> &v){
    if (L == R) return seg[x].data = v[L], void();
    int M = (L + R) / 2;
    build(lc, L, M, v);
    build(rc, M + 1, R, v);
    pull(x);
  }
  void modify(int x, int L, int R, int l, int r, int v) {
    if (r < L || R < l) return;
    if (l <= L && R <= r) return addtag(x, L, R, v);
    push(x, L, R);
    int M = (L + R) / 2;
    modify(lc, L, M, l, r, v);
    modify(rc, M + 1, R, l, r, v);
    pull(x);
  }
  int query(int x, int L, int R, int l, int r) {
    if (l <= L && R <= r) return seg[x].data;
    push(x, L, R);
    int M = (L + R) / 2;
    if (r <= M) return query(lc, L, M, l, r);
    if (l > M) return query(rc, M + 1, R, l, r);
    return query(lc, L, M, l, r) + query(rc, M + 1, R, l, r);
  }
  void build(vector<int> &v) {
    n = v.size() - 1; // 1-based
    build(1, 1, n, v);
  }
  // [l, r] += v
  void modify(int l, int r, int v) {
    modify(1, 1, n, l, r, v);
  }
  int query(int l, int r) {
    return query(1, 1, n, l, r);
  }
} st;