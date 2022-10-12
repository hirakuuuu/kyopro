#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc034/tasks/arc034_3

int main(){
    int a, b; cin >> a >> b;
    map<int, int> cnt;
    rep(i, b+1, a+1){
        int c = i;
        for(int j = 2; j*j <= c; j++){
            while(c%j == 0){
                cnt[j]++;
                c /= j;
            }
        }
        if(c > 1) cnt[c]++;
    }

    ll ans = 1;
    for(auto c: cnt){
        ans *= (c.second+1);
        ans %= MOD;
    }
    cout << ans << endl;
    
    return 0;
}