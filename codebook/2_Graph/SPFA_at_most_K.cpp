struct SPFA {
    int n;
    vector<vector<pii>> G;
    vector<bool> inq;
    vector<ll> d;
    SPFA(int n) : n(n), G(n), inq(n), d(n, LINF) {}
    void add_edge(int u, int v, int w) {
        G[u].emplace_back(v, w);
    }
    void solve(int s, int k){
        queue<int> q;
        d[s] = 0;
        q.emplace(s);
        inq[s] = true;
        vector<int> upd;
        vector<ll> bestd(n, LINF);
        while(!q.empty() && k--){
            while (!q.empty()) {
                int u = q.front(); q.pop();
                inq[u] = 0;
                for(auto &[v, w] : G[u]){
                    if(d[v] > d[u] + w){
                        if (bestd[v] == LINF)
                            upd.emplace_back(v);
                        bestd[v] = min(bestd[v], d[u] + w);
                    }
                }
            }
            for (auto &v : upd) {
                d[v] = bestd[v];
                bestd[v] = LINF;
                if (!inq[v]) {
                    inq[v] = 1;
                    q.emplace(v);
                }
            }
            upd.clear();
        }
    }
};