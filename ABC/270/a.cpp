#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc270/tasks/abc270_a

int main(){
    int a, b; cin >> a >> b;

    int ans = 0;

    rep(i, 0, 3){
        if((a&(1<<i)) or (b&(1<<i))) ans += (1<<i);
    }

    cout << ans << endl;
    
    return 0;
}