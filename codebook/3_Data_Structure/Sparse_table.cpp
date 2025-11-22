struct Sparse_table { // 0-based
  int st[__lg(MAXN) + 1][MAXN], n;
  void init(vector<int> &v) {
    n = v.size();
    for (int i = 0; i < n; ++i) st[0][i] = v[i];
    for (int i = 1, t = 2; t <= n; t <<= 1, i++)
      for (int j = 0; j + t <= n; j++)
        st[i][j] = max(st[i - 1][j], st[i - 1][j + t / 2]);
  }
  int query(int l, int r) { // [l, r]
    int t = __lg(r - l + 1);
    return max(st[t][l], st[t][r - (1 << t) + 1]);
  }
};
