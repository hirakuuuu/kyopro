#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc192/tasks/abc192_d


// n進数の大小比較は、桁ごとに見ないとオーバーフロー
string x;
ll m;
bool check(ll n){
    vector<ll> y;
    ll mm = m;
    while(mm > 0){
        y.push_back(mm%n);
        mm /= n;

    }
    reverse(y.begin(), y.end());
    if(y.size() < x.size()) return false;
    if(y.size() > x.size()) return true;

    rep(i, 0, x.size()){
        if(y[i] == x[i]-'0') continue;
        if(y[i] < x[i]-'0') return false;
        if(y[i] > x[i]-'0') return true;
    }

    return true;
}

int main(){
    cin >> x >> m;
    if(x.size() == 1){
        if(x[0]-'0' <= m) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }

    ll d = 0;
    for(auto xx: x){
        if(xx-'0' > d) d = xx-'0';
    }
    ll l = d, r = m+1;
    while(r-l > 1){
        ll mid = (l+r)/2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << l-d << endl;
    
    return 0;
}