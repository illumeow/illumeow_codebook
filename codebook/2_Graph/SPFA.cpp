struct SPFA {
    int n;
    vector<vector<pii>> G;
    vector<bool> inq;
    vector<ll> d;
    vector<int> cnt, len, p;
    SPFA(int n) : n(n), G(n), inq(n), d(n, LINF), cnt(n), len(n), p(n, -1) {}
    void add_edge(int u, int v, int w) {
        G[u].emplace_back(v, w);
    }
    bool solve(int s){
        deque<int> q;
        d[s] = 0;
        q.emplace_back(s);
        inq[s] = true;
        while(!q.empty()){
            int u = q.front(); q.pop_front();
            if(++cnt[u] >= n) return false;
            inq[u] = false;
            if(p[u] != -1 && inq[p[u]]) continue;
            for(auto &[v, w] : G[u]){
                if(d[v] > d[u] + w){
                    d[v] = d[u] + w;
                    p[v] = u;
                    if(!inq[v]){
                        if (!q.empty() && d[v] < d[q.front()]) q.emplace_front(v);
                        else q.emplace_back(v);
                        inq[v] = true;
                        len[v] = len[u] + 1;
                        if(len[v] >= n) return false;
                    }
                }
            }
        }
        return true;
    }
};