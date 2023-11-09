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
// https://atcoder.jp/contests/abc293/tasks/abc293_e

int main(){
    ll a, x, m; cin >> a >> x >> m;
    vector<ll> b(1000005), sum_b(1000005);
    sum_b[0] = b[0] = 1;
    rep(i, 1, 1000002){
        b[i] = (b[i-1]*a)%m;
        sum_b[i] = (sum_b[i-1]+b[i])%m;
    }

    ll tmp = 1, ans = 0;
    while(x > 1000000){
        ans += (tmp*sum_b[1000000-1])%m;
        ans %= m;
        tmp = (tmp*b[1000000])%m;
        x -= 1000000;
    }
    ans += (tmp*sum_b[x-1])%m;
    ans %= m;
    cout << ans << endl;
    
    
    return 0;
}