#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc253/tasks/abc253_d

ll gcd(ll a, ll b){
    if(a%b == 0) return b;
    else return gcd(b, a%b);
}

int main(){
    ll n, a, b; cin >> n >> a >> b;
    ll c = a*b/gcd(a, b);

    ll cnt_a = n/a, cnt_b = n/b, cnt_c = n/c;

    ll s = n*(n+1)/2, s_a = a*(cnt_a)*(cnt_a+1)/2, s_b = b*(cnt_b)*(cnt_b+1)/2, s_c = c*(cnt_c)*(cnt_c+1)/2;
    cout << s-s_a-s_b+s_c << endl; 
    
    return 0;
}