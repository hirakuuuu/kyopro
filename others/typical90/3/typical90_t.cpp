#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_t

/*
log2()を使うと誤差でだめ　→　整数のまま比較
・オーバーフローしないかだけ注意
*/

int main(){
    ll a, b, c; cin >> a >> b >> c;
    ll d = 1;
    while(b--) d *= c;
    if(a < d) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}