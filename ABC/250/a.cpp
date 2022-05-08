#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc250/tasks/abc250_a

int main(){
    int h, w; cin >> h >> w;
    int r, c; cin >> r >> c;

    int ans = 0;
    rep(i, 0, 4){
        int nr = r+(i-1)%2, nc = c+(i-2)%2;
        if(1 <= nr and nr <= h and 1 <= nc and nc <= w) ans++;
    }
    cout << ans << endl;
    
    return 0;
}