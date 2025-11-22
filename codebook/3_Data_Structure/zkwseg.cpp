template<class T, T (*op)(T, T), T (*e)()>
struct Seg {
    int n, sz;  // n: original, sz: power of 2
    vector<T> d;  // 1-based
    T get(int p){ return d[sz+p]; }
    void build(vector<T> &v){  // 0-based
        n = v.size(), sz = 1 << (__lg(n-1) + 1);
        d.assign(sz << 1, e());
        for(int i=0; i<n; ++i) d[sz+i] = v[i];
        for(int i=sz-1; i>=1; --i) d[i] = op(d[i<<1], d[i<<1|1]);
    }
    void build(int _n){
        build(vector<T>(_n, e()));
    }
    void modify(int p, T &x){  // d[p] = x
        p += sz, d[p] = x;
        while(p>>=1) d[p] = op(d[p<<1], d[p<<1|1]);
    }
    T query(int l, int r){  // [l, r)
        T sl = e(), sr = e();
        l += sz, r += sz;
        while(l < r) {
            if(l&1) sl = op(sl, d[l++]);
            if(r&1) sr = op(d[--r], sr);
            l >>= 1, r >>= 1;
        }
        return op(sl, sr);
    }
};

Seg<int, [](int a, int b){ return a + b; }, [](){ return 0; }> st;