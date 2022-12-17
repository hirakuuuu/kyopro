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
// https://atcoder.jp/contests/abc282/tasks/abc282_b

int main(){
    int n, m; cin >> n >> m;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];
    int ans = 0;

    rep(i, 0, n){
        rep(j, i+1, n){
            bool f = true;
            rep(k, 0, m){
                if(s[i][k] == 'x' and s[j][k] == 'x') f = false;
            }
            if(f) ans++;
        }
    }
    cout << ans << endl;


    
    return 0;
}