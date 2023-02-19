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
// https://atcoder.jp/contests/abc290/tasks/abc290_c

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    
    vector<int> cnt(k+1);
    rep(i, 0, n){
        if(a[i] <= k) cnt[a[i]]++;
    }

    vector<int> exist(k);
    exist[0] = (cnt[0] > 0);
    rep(i, 1, k){
        if(exist[i-1] and cnt[i] > 0) exist[i] = 1;
    }



    for(int i = k; i > 0; i--){
        if(exist[i-1] and n-cnt[i] >= k){
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;


    
    return 0;
}