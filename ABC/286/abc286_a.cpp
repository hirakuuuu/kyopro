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
// https://atcoder.jp/contests/abc286/tasks/abc286_a

int main(){
    int n, p, q, r, s; cin >> n >> p >> q >> r >> s;
    p--; q--; r--; s--;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n){
        if(p <= i and i <= q) b[i] = a[r+(i-p)];
        else if(r <= i and i <= s) b[i] = a[p+(i-r)];
        else b[i] = a[i];
    }
    rep(i, 0, n) cout << b[i] << ' ';
    cout << endl;
    
    return 0;
}