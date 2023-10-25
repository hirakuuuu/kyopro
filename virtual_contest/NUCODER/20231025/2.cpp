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
    ll n, k; cin >> n >> k;
    vector<ll> x(n);
    rep(i, 0, n) cin >> x[i];

    ll ans = INFINITY;
    rep(i, 0, n-k+1){
        if(x[i] <= 0 && 0 <= x[i+k-1]){
            chmin(ans, min(-x[i], x[i+k-1])+x[i+k-1]-x[i]);
        }else if(x[i+k-1] < 0){
            chmin(ans, -x[i]);
        }else{
            chmin(ans, x[i+k-1]);
        }
    }
    cout << ans << endl;
    
    return 0;
}