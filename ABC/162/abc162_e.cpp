#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc162/tasks/abc162_e

ll power(ll a, ll b, ll m=MOD){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

int main(){
    ll n, k; cin >> n >> k;
    ll ans = 0;
    vector<ll> cnt(k+1);
    vector<bool> used(k+1);
    rep(i, 2, k+1){
        cnt[i] += cnt[i-1];
        for(int j = 1; j*j <= i; j++){
            if(i%j == 0){        
                if(j > 1) cnt[i] += (power(i/j, n)-cnt[i/j])-(power(i/j-1, n)-cnt[i/j-1]);
                cnt[i] %= MOD;
                if(j != i/j) cnt[i] += (power(j, n)-cnt[j])-(power(j-1, n)-cnt[j-1]);
                cnt[i] %= MOD;
                if(cnt[i] < 0) cnt[i] += MOD;
            }
        }
    }

    rep(i, 1, k+1){
        ans += i*(power(k/i, n)-cnt[k/i]);
        ans %= MOD;
        if(ans < 0) ans += MOD;
    }
    cout << ans << endl;
    
    return 0;
}