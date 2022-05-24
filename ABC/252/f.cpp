#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc252/tasks/abc252_f


int main(){
    ll n, L; cin >> n >> L;
    vector<ll> a(n);
    ll s = 0;
    priority_queue<ll, vector<ll>, greater<ll>> que;
    rep(i, 0, n){
        cin >> a[i];
        s += a[i];
        que.push(a[i]);
    }
    if(L > s) que.push(L-s);
    ll ans = 0;
    while(que.size() > 1){
        ll q1 = que.top(); que.pop();
        ll q2 = que.top(); que.pop();
        ans += q1+q2;
        que.push(q1+q2);
    }

    cout << ans << endl;
    
    return 0;
}