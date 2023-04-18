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
// https://atcoder.jp/contests/arc152/tasks/arc152_b

int main(){
    ll n, l; cin >> n >> l;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<ll> b(n);
    rep(i, 0, n) b[i] = l-a[n-i-1];

    ll ans = 1LL<<60;

    rep(i, 0, n){
        auto itr = upper_bound(b.begin(), b.end(), a[i]);
        if(itr != b.end()) chmin(ans, 2*l+2*abs(*itr-a[i]));
        if(itr != b.begin()){
            --itr;
            chmin(ans, 2*l+2*abs(*itr-a[i]));
        }
    }
    cout << ans << endl;
    
    return 0;
}