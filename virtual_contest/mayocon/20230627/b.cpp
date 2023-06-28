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



int main(){
    int n, k; cin >> n >> k;
    vector<int> a(k);
    rep(i, 0, k){
        cin >> a[i];
        a[i]--;
    }
    vector<ll> x(n), y(n);
    rep(i, 0, n) cin >> x[i] >> y[i];

    ll ans = 0;
    rep(i, 0, n){
        ll tmp = INF;
        rep(j, 0, k){
            chmin(tmp, (x[i]-x[a[j]])*(x[i]-x[a[j]])+(y[i]-y[a[j]])*(y[i]-y[a[j]]));
        }
        chmax(ans, tmp);
    }

    printf("%.10f\n", sqrt(ans));
    
    return 0;
}