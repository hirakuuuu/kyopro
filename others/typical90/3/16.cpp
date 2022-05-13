#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_p

/*
枚数が10000未満で解ける　→　枚数でループすれば解けそう
・O(10^8)くらいは簡単な計算なら耐えそう
*/

int main(){
    ll n, a, b, c; cin >> n >> a >> b >> c;
    ll A = a, B = b, C = c;
    a = max(A, max(B, C));
    c = min(A, min(C, C));
    b = A+B+C-a-c;

    ll ans = 1LL<<60;
    rep(i, 0, 10000){
        if(a*i > n) break;
        
        rep(j, 0, 10000-i){
            if(a*i+b*j > n) break;
            if((n-a*i-b*j)%c == 0){
                ans = min(ans, i+j+(n-a*i-b*j)/c);
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}