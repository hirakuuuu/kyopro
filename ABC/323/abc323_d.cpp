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
// https://atcoder.jp/contests/abc323/tasks/abc323_d

int main(){
    ll n; cin >> n;
    map<ll, ll> cnt;
    set<ll> slime;
    rep(i, 0, n){
        ll s, c; cin >> s >> c;
        while(s%2 == 0){
            s /= 2;
            c *= 2;
        }
        slime.insert(s);
        cnt[s] += c;
    }
    

    ll ans = 0;
    for(auto ss: slime){
        ll tmp = cnt[ss];
        while(tmp){
            ans += tmp%2;
            tmp /= 2;
        }
    }

    cout << ans << endl;
    
    return 0;
}