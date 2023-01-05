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
// https://atcoder.jp/contests/agc060/tasks/agc060_a

ll dp[5005][26][26];

int main(){
    int n; cin >> n;
    string s; cin >> s;

    if(s[0] == '?' and s[1] == '?'){
        rep(i, 0, 26){
            rep(j, 0, 26){
                if(i != j) dp[2][i][j] = 1;
            }
        }
    }else if(s[0] == '?'){
        rep(i, 0, 26){
            if(i != s[1]-'a') dp[2][i][s[1]-'a'] = 1;
        }
    }else if(s[1] == '?'){
        rep(i, 0, 26){
            if(i != s[0]-'a') dp[2][s[0]-'a'][i] = 1;
        }
    }else{
        if(s[0] != s[1]) dp[2][s[0]-'a'][s[1]-'a'] = 1;
    }

    rep(i, 3, n+1){
        if(s[i-1] == '?'){
            rep(j, 0, 26){
                rep(k, 0, 26){
                    rep(l, 0, 26){
                        if(k == l or j == l) continue;
                        dp[i][k][l] += dp[i-1][j][k];
                        dp[i][k][l] %= mod;
                    }
                }
            }
        }else{
            rep(j, 0, 26){
                rep(k, 0, 26){
                    if(k == s[i-1]-'a' or j == s[i-1]-'a') continue;
                    dp[i][k][s[i-1]-'a'] += dp[i-1][j][k];
                    dp[i][k][s[i-1]-'a'] %= mod;
                }
            }
        }
    }

    ll ans = 0;
    rep(i, 0, 26){
        rep(j, 0, 26){
            ans += dp[n][i][j];
            ans %= mod;
        }
    }
    cout << ans << endl;



    return 0;
}