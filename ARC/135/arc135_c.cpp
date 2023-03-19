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
// https://atcoder.jp/contests/arc135/tasks/arc135_c

int main(){
    int n; cin >> n; 
    vector<ll> a(n);
    vector<ll> cnt(30);
    ll ans = 0;
    rep(i, 0, n){
        cin >> a[i];
        ans += a[i];
        rep(j, 0, 30){
            cnt[j] += ((a[i]&(1<<j)) > 0);
        }
    }

    rep(i, 0, n){
        ll tmp = 0;
        rep(j, 0, 30){
            if((a[i]&(1<<j)) > 0) tmp += (n-cnt[j])*(1LL<<j);
            else tmp += cnt[j]*(1LL<<j);
        }
        chmax(ans, tmp);
    }
    cout << ans << endl;


    
    return 0;
}