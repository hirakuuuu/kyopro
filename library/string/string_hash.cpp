#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bd

ll t[200005], h[200005];
ll power100[200005];

ll hash_value(int l, int r){
    ll val = h[r]-(h[l-1]*power100[r-l+1]%mod);
    if(val < 0) val += mod;
    return val;
}

int main(){
    int n, q; cin >> n >> q;
    string s; cin >> s;
    // 文字を数値に変換
    rep(i, 1, n+1) t[i] = (s[i-1]-'a')+1;
    // 100のn乗を前計算
    power100[0] = 1;
    rep(i, 1, n+1) power100[i] = 100LL*power100[i-1]%mod;
    // H[1], ... , H[n] を計算する
    h[0] = 0;
    rep(i, 1, n+1) h[i] = (100*h[i-1]+t[i])%mod;


    while(q--){
        int a, b, c, d; cin >> a >> b >> c >> d;
        if(hash_value(a, b) == hash_value(c, d)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}