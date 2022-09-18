#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc269/tasks/abc269_c

int main(){
    ll n; cin >> n;
    vector<int> pos;
    int cnt = 0;
    while(n){
        if(n%2 == 1){
            pos.push_back(cnt);
        }
        n /= 2;
        cnt++;
    }


    rep(i, 0, (1<<pos.size())){
        ll x = 0;
        rep(j, 0, pos.size()){
            if(((ll)i&(1LL<<j))){
                x += (1LL<<pos[j]);
            }
        }
        printf("%lld\n", x);
    }

    
    return 0;
}