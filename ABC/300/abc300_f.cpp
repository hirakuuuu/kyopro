#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc300/tasks/abc300_f

int main(){
    ll n, m, k; cin >> n >> m >> k;
    string s; cin >> s;

    vector<ll> xsum(n+1);
    rep(i, 0, n) xsum[i+1] = xsum[i]+(s[i] == 'x');

    ll ans = 0;
    rep(i, 0, n){
        ll ok = i+1, ng = n*m+1;
        while(ng-ok > 1){
            ll mid = (ok+ng)/2;
            ll xcnt = mid/n*xsum[n]+xsum[mid%n];
            if(xcnt-xsum[i] <= k) ok = mid;
            else ng = mid;
        }
        chmax(ans, ok-i);
    }
    cout << ans << endl;




    
    return 0;
}