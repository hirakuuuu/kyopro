#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc297/tasks/abc297_e

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());

    set<ll> s;
    rep(i, 0, n) s.insert(a[i]);
    int cnt = 1;
    while(cnt < k){
        ll tmp = *s.begin();
        s.erase(s.begin());
        rep(i, 0, n) s.insert(tmp+a[i]);
        cnt++;
    }
    cout << *s.begin() << endl;

    
    return 0;
}