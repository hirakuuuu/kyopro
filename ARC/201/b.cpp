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
        ll w; cin >> w;
        vector<vector<ll>> items(61);
        rep(i, 0, n){
            int x; cin >> x;
            ll y; cin >> y;
            items[x].push_back(y);
        }
        ll ans = 0;
        rep(i, 0, 60){
            sort(items[i].begin(), items[i].end());
            if(((w>>i)&1) && !items[i].empty()){
                ans += items[i].back();
                items[i].pop_back();
                w -= 1LL<<i;
            }
            while(items[i].size() >= 2){
                ll tmp = 0;
                rep(_, 0, 2){
                    tmp += items[i].back();
                    items[i].pop_back();
                }
                items[i+1].push_back(tmp);
            }
            if(!items[i].empty()){
                items[i+1].push_back(items[i].back());
                items[i].pop_back();
            }
        }
        cout << ans << endl;
    }
    return 0;
}