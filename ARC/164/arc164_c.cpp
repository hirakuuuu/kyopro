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
// https://atcoder.jp/contests/arc164/tasks/arc164_c

int main(){
    int n; cin >> n;
    vector<ll> a(n), b(n);
    rep(i, 0, n) cin >> a[i] >> b[i];

    set<pll> s;
    rep(i, 0, n){
        s.insert({a[i]-b[i], a[i]});
    }

    ll ans = 0;
    rep(i, 0, n){
        pll alice = *s.rbegin();
        s.erase(s.find(alice));
        s.insert({-alice.first, alice.second-alice.first});
    
        pll bob = *s.rbegin();
        s.erase(s.find(bob));
        ans += bob.second;
    }

    cout << ans << endl;
    
    return 0;
}