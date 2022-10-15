#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc273/tasks/abc273_b



int main(){
    ll x, k; cin >> x >> k;

    ll warusu = 1;
    rep(i, 0, k){
        if(x%(warusu*10)/warusu >= 5){
            x = x-x%(warusu*10)+warusu*10;
        }else{
            x = x-x%(warusu*10);
        }
        warusu *= 10;
    } 

    cout << x << endl;



    
    return 0;
}