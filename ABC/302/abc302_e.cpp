#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc302/tasks/abc302_e

int main(){
    int n, q; cin >> n >> q;
    vector<int> t(q), u(q), v(q);
    vector<set<int>> g(n+1);
    int ans = 0;
    rep(i, 0, q){
        cin >> t[i];
        if(t[i] == 1){
            cin >> u[i] >> v[i];
            if(!g[u[i]].size()) ans++;
            if(!g[v[i]].size()) ans++;
            g[u[i]].insert(v[i]);
            g[v[i]].insert(u[i]);
        }else{
            cin >> v[i];
            for(auto gg: g[v[i]]){
                g[gg].erase(v[i]);
                if(!g[gg].size()) ans--;
            }
            if(g[v[i]].size()){
                g[v[i]] = set<int>();
                ans--;
            }
        }
        cout << n-ans << endl;
    }


    
    return 0;
}