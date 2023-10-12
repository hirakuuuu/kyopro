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
    ll n, h; cin >> n >> h;
    vector<ll> a(n), b(n);
    rep(i, 0, n){
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end());
    vector<ll> c;
    rep(i, 0, n){
        if(a[n-1] <= b[i]) c.push_back(b[i]);
    }
    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());

    ll ans = 0, tmp = h;
    for(auto cc: c){
        tmp -= cc;
        ans++;
        if(tmp <= 0) break;
    }

    if(tmp <= 0) cout << ans << endl;
    else cout << ans+(tmp+a[n-1]-1)/a[n-1] << endl;

    return 0;
}