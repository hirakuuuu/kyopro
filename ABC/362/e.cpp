#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    if(n == 1){
        cout << 1 << endl;
        return 0;
    }else if(n == 2){
        cout << 2 << ' ' << 1 << endl;
        return 0;
    }

    
    vector<mint> ans(n+1);
    ans[1] = n;
    ans[2] = n*(n-1)/2;

    set<ll> d;
    rep(i, 0, n){
        rep(j, i+1, n){
            d.insert(a[j]-a[i]);
        }
    }
    for(auto dd: d){
        vector<vector<int>> g(n);
        vector<vector<mint>> dp(n, vector<mint>(n+1));
        rep(i, 0, n){
            rep(j, i+1, n){
                if(a[j]-a[i] == dd){
                    g[j].push_back(i);
                }
            }
        }
        rrep(i, n-1, 0){
            dp[i][1]++;
            for(auto l: g[i]){
                rep(k, 1, n){
                    dp[l][k+1] += dp[i][k];
                }
            }
        }

        rep(k, 3, n+1){
            rep(i, 0, n){
                ans[k] += dp[i][k];
            }
        }
    }
    rep(i, 1, n+1){
        cout << ans[i].val() << ' ';
    }
    cout << endl;


    
    return 0;
}