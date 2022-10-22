#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/agc023/tasks/agc023_b

int main(){
    int n; cin >> n;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];
    int ans = 0;

    rep(i, 0, n){
        bool f = true;
        rep(j, 0, n){
            rep(k, 0, n){
                if(s[j][k] != s[(k+i)%n][(j-i+n)%n]){
                    f = false;
                }
            }
        }
        if(f){
            ans += n;
        }
    }

    cout << ans << endl;
    
    return 0;
}