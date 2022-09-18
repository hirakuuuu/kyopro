#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc127/tasks/arc127_a

int main(){
    ll n; cin >> n;
    ll o = 1, ans = 0, cnt = 1;

    rep(i, 0, 20){
        ans += cnt;
        cnt = 10*cnt+1;
        o *= 10;
        if(2*o > n) break;
    }


    ll O = o;

    while(o > 0){
        if(n >= O){
            ans += min(n-O+1, cnt-cnt/10);
        }
        o /= 10;
        O += o;
        cnt /= 10;
    }

    cout << ans << endl;





    return 0;
}