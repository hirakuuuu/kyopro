#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc296/tasks/abc296_d

int main(){
    ll n, m; cin >> n >> m;
    if(sqrt(m) > n){
        cout << -1 << endl;
    }else if(m <= n){
        cout << m << endl;
    }else{
        ll ans = 1LL<<60;
        rep(i, (m+n-1)/n, sqrt(m)+1){
            ll tmp = m+(i-m%i)%i;
            chmin(ans, tmp);
        }
        cout << ans << endl;
    }
    
    return 0;
}