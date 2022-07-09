#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://onlinejudge.u-aizu.ac.jp/problems/1179

int main(){
    int n; cin >> n;
    rep(i, 0, n){
        int y, m, d; cin >> y >> m >> d;
        int ans = 0;
        int rest_y = 999-y;
        rep(j, 0, rest_y){
            if(j%3 == 0) ans += 20*10;
            else ans += 20*10-5;
        }

        if(y%3 == 0){
            ans += 21-d;
            ans += (10-m)*20;
        }else{
            if(m%2) ans += 21-d;
            else ans += 20-d;
            ans += (11-m)/2*19+(10-m)/2*20;
        }
        cout << ans << endl;
    }
    
    return 0;
}