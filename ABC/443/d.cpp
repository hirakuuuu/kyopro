#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> r(n);
        vector<pair<ll, ll>> p(n);
        vector<vector<int>> g(n+1);
        rep(i, 0, n){
            cin >> r[i]; r[i]--;
            g[r[i]].push_back(i);
        }
        queue<pair<ll, ll>> que;
        vector<ll> s(n, -1);
        rep(i, 0, n){
            for(auto id: g[i]){
                if(s[id] != -1) continue;
                s[id] = i;
                if(id > 0 && s[id-1] == -1){
                    g[i+1].push_back(id-1);
                }
                if(id < n-1 && s[id+1] == -1){
                    g[i+1].push_back(id+1);
                }
            }
        }
        rep(i, 0, n){
            if(s[i] == -1) s[i] = n-1;
        }

        ll ans = 0;
        rep(i, 0, n) ans += r[i]-s[i];
        cout << ans << endl;

    }
    return 0;
}