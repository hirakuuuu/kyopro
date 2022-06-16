#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/code-festival-2014-final/tasks/code_festival_final_c

map<ll, ll> f_map;

ll f(ll k){
    ll res = 0, o = 1, k_ = k;
    while(k_){
        res += (k_%10)*o;
        k_ /= 10;
        if(k_ == 0) break;
        o *= k;
    }
    return res;
}

void init_f(){
    rep(i, 10, 10005){
        if(f_map[f(i)] == 0) f_map[f(i)] = i;
    }
}

int main(){
    ll n; cin >> n;
    init_f();
    if(f_map[n]) cout << f_map[n] << endl;
    else cout << -1 << endl;
    
    return 0;
}