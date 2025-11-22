struct BIT {  // 1-based
  int bit[MAXN + 1], n;
  #define lb(x) (x & -x)
  void build(vector<int> &data){
    n = data.size()-1;
    for (int i = 1, t; i <= n; ++i) {
      bit[i] = data[i], t = i - lb(i);
      for (int j = i - 1; j > t; j -= lb(j))
        bit[i] += bit[j];
    }
  }
  void modify(int x, int v){
    for (; x; x += lb(x)) bit[x] += v;
  }
  int query(int x){
    int re = 0;
    for (; x; x -= lb(x)) re += bit[x];
    return re;
  }
  // smallest x, cnt[1..x] <= k
  int query_kth(int k){
    int res = 0;
    for (int i = (1 << __lg(n)); i; i >>= 1)
        if (res + i < n && bit[res + i] < k)
            k -= bit[res += i];
    return res + 1;
  }
};
