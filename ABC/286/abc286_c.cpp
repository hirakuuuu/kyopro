#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc286/tasks/abc286_c

int main(){
    ll n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    ll ans = 1LL<<60;
    rep(i, 0, n){
        ll tmp = a*i;
        rep(j, 0, n/2){
            if(s[(j+i)%n] != s[(n-j-1+i)%n]) tmp += b;
        }        
        chmin(ans, tmp);
    }
    cout << ans << endl;
    
    return 0;
}