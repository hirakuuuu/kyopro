#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc142/tasks/abc142_d

vector<ll> p;

ll gcd(ll a, ll b){
    if(a%b == 0) return b;
    else return gcd(b, a%b);
}

int main(){
    ll a, b; cin >> a >> b;
    ll c = gcd(a, b);
    vector<int> e(1000005);
    rep(i, 2, 1000005){
        if(e[i] == 0){
            p.push_back(i);
            for(int j = i; j <= 1000005; j += i) e[j] = 1;
        }
    }
    int ans = 1;
    for(auto pn: p){
        if(c%pn == 0){
            ans++;
            while(c%pn == 0) c /= pn;
        }
    }
    if(c != 1) ans++;
    cout << ans << endl;
    return 0;
}