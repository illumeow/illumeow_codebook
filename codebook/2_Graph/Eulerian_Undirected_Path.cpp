struct EulerianPath {
    int n, m;
    vector<vector<pii>> adj;
    vector<int> deg, path;
    vector<bool> used;
    EulerianPath(int _n, int _m): n(_n), m(_m), adj(_n), deg(_n), used(_m) {}
    void add_edge(int u, int v, int i) {
        adj[u].eb(v, i);
        adj[v].eb(u, i);
        deg[u]++;
        deg[v]++;
    }
    bool valid() {
        int odd = 0;
        for (int d : deg) {
            if (d & 1) odd++;
        }
        return odd == 0 || odd == 2;
    }
    int start() {
        int s = 0;
        for (int i = 0; i < n; i++) {
            if (deg[i] & 1) return i;
            if (deg[i] > 0) s = i;
        }
        return s;
    }
    bool solve() {
        if (!valid()) return false;
        stack<int> st;
        st.push(start());
        while (!st.empty()) {
            int u = st.top();
            while (!adj[u].empty() && used[adj[u].back().ss]) {
                adj[u].pop_back();
            }
            if (adj[u].empty()) {
                path.eb(u);
                st.pop();
            } else {
                auto [v, i] = adj[u].back();
                adj[u].pop_back();
                used[i] = true;
                st.push(v);
            }
        }
        reverse(all(path));
        return path.size() == m + 1;
    }
};