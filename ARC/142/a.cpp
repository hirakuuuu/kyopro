#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc142/tasks/arc142_a

int main(){
    ll n, k; cin >> n >> k;

    ll rk = 0, ck = k, cnt = 0;
    while(ck){
        rk += ck%10;
        ck /= 10;
        rk *= 10;
    }
    rk /= 10;

    if(k <= rk){
        ck = k;
        while(ck <= n){
            ck *= 10;
            cnt++;
        }
        if(k < rk){
            ck = rk;
            while(ck <= n){
                ck *= 10;
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}