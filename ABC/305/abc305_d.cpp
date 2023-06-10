#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc305/tasks/abc305_d

int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<ll> sum_a(n+1);
    rep(i, 0, (n-1)/2){
        sum_a[2*i+1] = sum_a[2*i];
        sum_a[2*i+2] = sum_a[2*i]+(a[2*i+2]-a[2*i+1]);
    }


    ll q; cin >> q;
    while(q--){
        ll l, r; cin >> l >> r;
        int pos_l = lower_bound(a.begin(), a.end(), l)-a.begin();
        int pos_r = lower_bound(a.begin(), a.end(), r)-a.begin();

        ll time_l = 0,  time_r = 0;
        if(pos_l%2 == 0) time_l = sum_a[pos_l]-(a[pos_l]-l);
        else time_l = sum_a[pos_l];
        
        if(pos_r%2 == 0) time_r = sum_a[max(0, pos_r-1)]+(r-a[max(0, pos_r-1)]);
        else time_r = sum_a[pos_r];

        cout << time_r-time_l << endl;
    }
    
    return 0;
}