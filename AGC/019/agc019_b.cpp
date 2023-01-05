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
// https://atcoder.jp/contests/agc019/tasks/agc019_b

int main(){
    string s; cin >> s;
    int n = s.size();
    vector<vector<int>> cnt(n+1, vector<int>(26));
    rep(i, 1, n+1){
        rep(j, 0, 26){
            if(j == s[i-1]-'a') cnt[i][j] = cnt[i-1][j]+1;
            else cnt[i][j] = cnt[i-1][j];
        }
    }

    ll ans = 1;
    rep(i, 1, n+1){
        ans += (n-i)-(cnt[n][s[i-1]-'a']-cnt[i][s[i-1]-'a']);
    }
    cout << ans << endl;
    
    return 0;
}