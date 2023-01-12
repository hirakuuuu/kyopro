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
// https://atcoder.jp/contests/agc026/tasks/agc026_b

int main(){
    ll t; cin >> t;
    while(t--){
        ll a, b, c, d; cin >> a >> b >> c >> d;
        ll bd = gcd(b, d);
        if(a < b or d < b or (c < b and bd-(b-c) < a%bd)) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    
    return 0;
}