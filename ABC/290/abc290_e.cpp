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
// https://atcoder.jp/contests/abc290/tasks/abc290_e

int main(){
    ll n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<vector<ll>> pos(n+1);
    rep(i, 0, n){
        pos[a[i]].push_back(i+1);
    }

    ll ans = 0;
    rep(i, 1, n+1){
        ans += (ll)(i/2)*(n-i+1);
    }

    rep(i, 1, n+1){
        ll l = 0, r = pos[i].size()-1;
        while(l < r){
            if(pos[i][l] < (n+1-pos[i][r])){
                ans -= (r-l)*pos[i][l];
                l++;
            }else{
                ans -= (r-l)*(n+1-pos[i][r]);
                r--;
            }
        }
    }

    cout << ans << endl;

    
    return 0;
}