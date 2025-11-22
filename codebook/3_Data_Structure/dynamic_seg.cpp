struct Segment_Tree {  // dynamic
  struct node {
    int data, tag;
    node *l, *r;
    node() : data(0), tag(0), l(0), r(0) {}
    void up() {
      if (l) data = min(l->data, r->data);
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
  node *_build(int l, int r, vector<int> &data) {
    node *p = new node();
    if (l == r) return p->data = data[l], p;
    int m = (l + r) / 2;
    p->l = _build(l, m, data),
    p->r = _build(m + 1, r, data);
    return p->up(), p;
  }
  void _modify(  // [l, r] += x
    int l, int r, int L, int R, node *p, int x) {
    if (r < L || R < l) return;
    p->down();
    if (l <= L && R <= r)
      return p->data += x, p->tag += x, void();
    int M = (L + R) / 2;
    _modify(l, r, L, M, p->l, x);
    _modify(l, r, M + 1, R, p->r, x);
    p->up();
  }
  int _query(int l, int r, int L, int R, node *p) {
    p->down();
    if (l <= L && R <= r) return p->data;
    int M = (L + R) / 2;
    if (r <= M) return _query(l, r, L, M, p->l);
    if (L > M) return _query(l, r, M + 1, R, p->r);
    return min(_query(l, r, L, M, p->l),
               _query(l, r, M + 1, R, p->r));
  }
  void build(int l, int r, vector<int> &data) {
    L = l, R = r;
    root = _build(l, r, data);
  }
  void modify(int l, int r, int x) {
    _modify(l, r, L, R, root, x);
  }
  int query(int l, int r) {
    return _query(l, r, L, R, root);
  }
};