#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, m; cin >> n >> m;
    vector<int> h(n+1);
    rep(i, 1, n+1) cin >> h[i];
    
    vector<vector<int>> g(n+1);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int ans = 0;
    rep(i, 1, n+1){
        bool f = true;
        for(const auto gg: g[i]){
            if(h[i] <= h[gg]) f = false;
        }
        ans += f;
    }
    cout << ans << endl;


    
    return 0;
}