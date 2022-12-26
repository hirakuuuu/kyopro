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
// https://atcoder.jp/contests/agc053/tasks/agc053_b

int main(){
    int n; cin >> n;
    vector<ll> v(2*n);
    ll ans = 0;
    rep(i, 0, 2*n){
        cin >> v[i];
        ans += v[i];
    }
    priority_queue<ll, vector<ll>, greater<ll>> que;
    rep(i, 0, n){
        que.push(v[n-i-1]);
        que.push(v[n+i]);
        ans -= que.top(); que.pop();
    }
    cout << ans << endl;
    
    return 0;
}