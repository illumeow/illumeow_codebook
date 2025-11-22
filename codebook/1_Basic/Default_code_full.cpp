#include<bits/stdc++.h>
// #define int long long
#define ff first
#define ss second
#define X first
#define Y second
#define all(a) a.begin(),a.end()
#define SZ(a) (int)(a.size())
#define pb push_back
#define eb emplace_back
#define FOR(i,a,b) for(int i=a,Z=b;i<Z;++i)
#define FOR1(i,a,b) for(int i=a,Z=b;i<=Z;++i)
#define ROF(i,a,b) for(int i=a,Z=b;i>Z;--i)
#define ROF1(i,a,b) for(int i=a,Z=b;i>=Z;--i)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vi>;
template<typename T, typename U>ostream& operator<<(ostream&os,const pair<T,U>&p)
{return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T> ostream& operator<<(ostream&os,const vector<T>&v)
{os<<"[";for(int i=0;i<SZ(v);++i)os<<v[i]<<(i==SZ(v)-1?"]":", ");return os;}
#ifdef D
template<typename T> void _dbg(T x){cerr<<x<<endl;}
template<typename T,typename ...U> void _dbg(T x,U ...y){cerr<<x<<", ";_dbg(y...);}
#define dbg(...) do{cerr<<"\033[1;33m"<<#__VA_ARGS__<<" = ";_dbg(__VA_ARGS__);cerr<<"\033[0m";}while(0)
#else
#define dbg(...) void(0)
#endif
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;

void foo(){
    
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) foo();
}
