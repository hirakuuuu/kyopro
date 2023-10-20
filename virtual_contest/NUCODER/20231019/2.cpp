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
    ll n, m; cin >> n >> m;
    vector<ll> h(n), w(m);
    rep(i, 0, n) cin >> h[i];
    rep(i, 0, m) cin >> w[i];
    sort(h.begin(), h.end());
    vector<int> sum_e(n+1), sum_o(n+1);
    rep(i, 1, n){
        if(i%2 == 1) sum_o[i] = sum_o[i-1]+abs(h[i]-h[i-1]);
        else sum_o[i] = sum_o[i-1];
    }
    rrep(i, n-1, 0){
        if(i%2 == 1) sum_e[i] = sum_e[i+1]+abs(h[i]-h[i+1]);
        else sum_e[i] = sum_e[i+1];
    }

    ll ans = INFINITY;
    rep(i, 0, m){
        int pos = lower_bound(h.begin(), h.end(), w[i])-h.begin();
        ll tmp = 0;
        if(pos%2 == 0) tmp += sum_o[pos]+abs(h[pos]-w[i])+sum_e[pos+1];
        else tmp += sum_o[pos-1]+abs(h[pos-1]-w[i])+sum_e[pos];
        chmin(ans, tmp);
    }
    cout << ans << endl;
    
    return 0;
}