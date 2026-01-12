struct EulerianPath {
    int n, m;
    vector<vector<int>> adj;
    vector<int> in, out, path;
    EulerianPath(int _n, int _m): n(_n), m(_m), adj(_n), in(_n), out(_n) {}
    void add_edge(int u, int v) {
        adj[u].eb(v);
        out[u]++;
        in[v]++;
    }
    bool valid() {
        int s = 0, t = 0;
        for (int i = 0; i < n; i++) {
            if (out[i] - in[i] == 1) s++;
            else if (in[i] - out[i] == 1) t++;
            else if (in[i] != out[i]) return false;
        }
        return (s == 1 && t == 1) || (s == 0 && t == 0);
    }
    int start() {
        int s = 0;
        for (int i = 0; i < n; i++) {
            if (out[i] - in[i] == 1) return i;
            if (out[i] > 0) s = i;
        }
        return s;
    }
    bool solve() {
        if (!valid()) return false;
        stack<int> st;
        st.push(start());
        while (!st.empty()) {
            int u = st.top();
            if (adj[u].empty()) {
                path.eb(u);
                st.pop();
            } else {
                int v = adj[u].back();
                adj[u].pop_back();
                st.push(v);
            }
        }
        reverse(all(path));
        return path.size() == m + 1;
    }
};