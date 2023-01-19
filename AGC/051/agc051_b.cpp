#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/agc051/tasks/agc051_b

int main(){

    cout << 1000 << endl;
    rep(i, 0, 10){
        rep(j, 0, 10){
            rep(k, 0, 10){
                cout << i+100*k << ' ' << 10*j+100*k << endl;
            }
        }
    }
    
    return 0;
}