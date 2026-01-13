struct DSU {
    vector<int> p, rk;
    DSU(int n): p(n), rk(n) {
        iota(all(p), 0);
    }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (rk[x] < rk[y]) swap(x, y);
        p[y] = x;
        if (rk[x] == rk[y]) rk[x]++;
        return true;
    }
};