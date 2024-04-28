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
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<vector<int>> val(m);
    rep(i, 0, n){
        if(a[i] >= 0){
            for(int j = a[i]+(i+1), k = 0; j <= n && k < m; j += (i+1), k++){
                val[k].push_back(j);
            }
        }else{
            int l = (-a[i]+i)/(i+1)-1;
            for(int j = a[i]+(i+1)*(l+1), k = l; j <= n && k < m; j += (i+1), k++){
                val[k].push_back(j);
            }
        }
    }
    rep(i, 0, m){
        sort(val[i].begin(), val[i].end());
        int ans = 0;
        rep(j, 0, n+1){
            auto itr = lower_bound(val[i].begin(), val[i].end(), j);
            if(itr == val[i].end() || *itr != j){
                ans = j;
                break;
            }
        }
        cout << ans << endl;

    }
    return 0;
}