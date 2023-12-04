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
// https://atcoder.jp/contests/abc297/tasks/abc297_g

int main(){
    ll n, l, r; cin >> n >> l >> r;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    if(l == r){
        ll cnt = 0;
        rep(i, 0, n) cnt += a[i]/l;
        if(cnt%2) cout << "First" << endl;
        else cout << "Second" << endl; 
    }else if(l == 1){
        ll xora = 0;
        rep(i, 0, n) xora ^= a[i]%(r+1);
        if(xora) cout << "First" << endl;
        else cout << "Second" << endl;
    }else{
        rep(i, 0, n) a[i] %= (l+r);
        ll cnt = 0;
        rep(i, 0, n) cnt ^= a[i]/l;
        if(cnt) cout << "First" << endl;
        else cout << "Second" << endl;
    }



    
    return 0;
}