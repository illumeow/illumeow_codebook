struct Segment_Tree {  // dynamic
  struct node {
    int data, tag;
    node *l, *r;
    node() : data(0), tag(0), l(0), r(0) {}
    void up() {
      if (l) data = max(l->data, r->data);
    }
    void down() {
      if (l) {
        l->data += tag, l->tag += tag;
        r->data += tag, r->tag += tag;
      }
      tag = 0;
    }
  } * root;
  int L, R;
  node *build(int l, int r, vector<int> &data) {
    node *p = new node();
    if (l == r) return p->data = data[l], p;
    int m = (l + r) / 2;
    p->l = build(l, m, data),
    p->r = build(m + 1, r, data);
    return p->up(), p;
  }
  void _modify(  // [l, r] += x
    int l, int r, int L, int R, node *p, int x) {
    if (r < L || R < l) return;
    p->down();
    if (L <= l && R >= r)
      return p->data += x, p->tag += x, void();
    int m = (l + r) / 2;
    _modify(L, R, l, m, p->l, x);
    _modify(L, R, m + 1, r, p->r, x);
    p->up();
  }
  int _query(int l, int r, int L, int R, node *p) {
    p->down();
    if (l <= L && R <= r) return p->data;
    int M = (L + R) / 2;
    if (r <= M) return _query(l, r, L, M, p->l);
    if (L > M) return _query(l, r, M + 1, R, p->r);
    return max(_query(l, r, L, M, p->l),
               _query(l, r, M + 1, R, p->r));
  }
  void init(int l, int r, vector<int> &data) {
    L = l, R = r;
    root = build(l, r, data);
  }
  void modify(int l, int r, int x) {
    _modify(l, r, L, R, root, x);
  }
  int query(int l, int r) {
    return _query(l, r, L, R, root);
  }
};
