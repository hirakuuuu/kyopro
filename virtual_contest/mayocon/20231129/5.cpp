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
// 

int main(){
    int n, m; cin >> n >> m;
    vector<vector<ll>> x(n, vector<ll>(3));
    rep(i, 0, n){
        rep(j, 0, 3) cin >> x[i][j];
    }

    ll ans = -9e18;
    rep(k, 0, 8){
        vector<int> c(3, 1);
        rep(j, 0, 3){
            if((k&(1<<j)) > 0) c[j] = -1;
        }

        vector<ll> sum(n);
        rep(i, 0, n){
            rep(j, 0, 3){
                sum[i] += x[i][j]*c[j];
            }
        }

        sort(sum.rbegin(), sum.rend());
        ll tmp = 0;
        rep(i, 0, m) tmp += sum[i];
        chmax(ans, tmp);
    }
    cout << ans << endl;
    
    return 0;
}