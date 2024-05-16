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
// using mint = modint998244353;
vector<ll> MOD = {998244353, 1000000007};
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}



int main(){
    int n; cin >> n;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];

    map<pair<ll, ll>, ll> cnt;
    ll ans = 0;
    rep(i, 0, n){
        vector<ll> m(2);
        rep(j, 0, s[i].size()){
            rep(k, 0, 2) m[k] = (m[k]*27+(s[i][j]-'a'+1))%MOD[k];
            ans += cnt[{m[0], m[1]}]; 
        }
        m[0] = m[1] = 0;
        rep(j, 0, s[i].size()){
            rep(k, 0, 2) m[k] = (m[k]*27+(s[i][j]-'a'+1))%MOD[k];
            cnt[{m[0], m[1]}]++; 
        }
    }

    cout << ans << endl;


    
    return 0;
}