#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_bd

bool dp[105][2][100005];

int main(){
    ll n, s; cin >> n >> s;
    vector<ll> a(n+1), b(n+1);
    rep(i, 1, n+1) cin >> a[i] >> b[i];

    dp[0][0][0] = dp[0][1][0] = true;
    rep(i, 1, n+1){
        rep(j, 0, s+1){
            if(dp[i-1][0][j] or dp[i-1][1][j]){
                if(j+a[i] <= s) dp[i][0][j+a[i]] = true;
                if(j+b[i] <= s) dp[i][1][j+b[i]] = true;
            }
        }
    }
    string ans;
    if(dp[n][0][s] or dp[n][1][s]){
        ll tmp = s;
        rep(i, 0, n){
            if(dp[n-i][0][tmp]){
                ans += 'A';
                tmp -= a[n-i];
            }else{
                ans += 'B';
                tmp -= b[n-i];        
            }
        }
        reverse(ans.begin(), ans.end());
    }else{
        ans = "Impossible";
    }

    cout << ans << endl;

    
    return 0;
}