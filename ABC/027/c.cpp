#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc027/tasks/abc027_c

int main(){
    ll n; cin >> n;
    ll m = n, cnt = 0;
    while(m > 0){
        cnt++;
        m /= 2;
    }
    ll x = 1;
    if((cnt)%2){
        rep(i, 0, cnt-1){
            if(i%2) x = 2*x;
            else x = 2*x+1;
        }
        if(x > n){
            cout << "Takahashi" << endl;
        }else{
            cout << "Aoki" << endl;
        }
    }else{
        rep(i, 0, cnt-1){
            if(i%2) x = 2*x+1;
            else x = 2*x;
        }
        if(x <= n){
            cout << "Takahashi" << endl;
        }else{
            cout << "Aoki" << endl;
        }
    }

    return 0;
}