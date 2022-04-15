#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc161/tasks/abc161_f

vector<vector<ll>> v(2);
void func(ll n, int f){
    for(ll i = 1; i*i <= n; i++){
        if(n%i) continue;
        v[f].push_back(i);
        if(n/i != i) v[f].push_back(n/i);
    }
}

int main(){
    ll n; cin >> n;
    func(n-1, 0);
    func(n, 1);

    ll ans = v[0].size()-1;
    for(auto vv: v[1]){
        ll m = n;
        if(vv == 1) continue;
        while(m%vv == 0) m /= vv;
        if(m%vv == 1) ans++;
    }
    cout << ans << endl;    
    return 0;
}