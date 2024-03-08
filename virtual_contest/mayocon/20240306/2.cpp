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
    ll n; cin >> n;
    ll ans = 0;
    rep(i, 1, 1000001){
        ll tmp = (ll)i*i*i;
        if(tmp > n) break;
        string s = to_string(tmp);
        string t = s;
        reverse(t.begin(), t.end());
        if(s == t) chmax(ans, tmp);
    }
    cout << ans << endl;
    
    return 0;
}