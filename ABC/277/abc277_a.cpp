#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc277/tasks/abc277_a

int main(){
    int n, x; cin >> n >> x;
    int ans = 0;
    rep(i, 0, n){
        int p; cin >> p;
        if(x == p) ans = i+1;
    }

    cout << ans << endl;
    
    return 0;
}