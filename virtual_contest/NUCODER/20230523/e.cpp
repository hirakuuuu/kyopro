#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(ll i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

vector<ll> a(100);
map<pll, ll> memo;
ll f(ll x, ll i){
    if(memo[{x, i}] > 0) return memo[{x, i}];
    if(a[i+1] == 0) return x/a[i];

    return memo[{x, i}] = min((x%a[i+1])/a[i]+f(x-x%a[i+1], i+1), (a[i+1]-x%a[i+1])/a[i]+f(x+(a[i+1]-x%a[i+1]), i+1));

}

int main(){
    ll n, x; cin >> n >> x;
    rep(i, 0, n) cin >> a[i];
    cout << f(x, 0) << endl;
    
    return 0;
}