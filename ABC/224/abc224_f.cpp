#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc224/tasks/abc224_f

ll power(ll a, ll b, ll m=mod){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

int main(){
    string s; cin >> s;
    int n = s.size();

    vector<vector<ll>> cnt(n+1, vector<ll>(10));
    vector<vector<ll>> m(n+1, vector<ll>(10));

    rep(i ,0, n){
        rep(j, 1, 10){
            cnt[n-i-1][j] = cnt[n-i][j];
            if(s[i]-'0' == j) cnt[n-i-1][j]++;
        }
    }



    rep(i, 0, n){
        rep(j, 1, 10){
            if(i == 0) m[i][j] = j;
            else m[i][j] = (m[i-1][j]*10)%mod;
        }
    }

    ll ans = m[n-1][s[0]-'0'];
    
    rep(i, 0, n-1){
        ll total_m = 0;
        rep(j, 1, 10){
            total_m += m[i][j]*cnt[i][j];
            if(s[n-i-1]-'0' == j) total_m += m[i][j];
            total_m %= mod;
        }
        ans += total_m*power(2, n-i-2);
        ans %= mod;
    }
    cout << ans << endl;
    
    return 0;
}