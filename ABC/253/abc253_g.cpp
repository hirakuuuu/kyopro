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
// https://atcoder.jp/contests/abc253/tasks/abc253_g





int main(){
    ll n, l, r; cin >> n >> l >> r;
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 1);
    ll tmp = 0;
    ll a = -1, b = -1, k = 0, c = -1;
    rep(i, 0, n){
        if(tmp < l && l <= tmp+(n-i-1)){
            a = i;
            b = i+(l-tmp);
        }else if(l < tmp && tmp+(n-i-1) < r){
            k++;
        }else if(tmp < r && r <= tmp+(n-i-1)){
            c = i+r-tmp;
        }
        tmp += n-i-1;
    }

    cout << a << ' ' << b << ' ' << k << ' ' << c << endl;
    if(a != -1 && b != -1){
        rep(i, b, min(b+(r-l+1), n)) swap(ans[a], ans[i]);
    }
    if(k > 0){
        vector<int> ans_ = ans;
        rep(i, a+1, n) ans_[i] = ans[n-(i-a-1)-1];
        ans = ans_;
        rep(i, a+k+1, n) ans[i] = ans_[n-(i-(a+k+1))-1];
    }

    if(c != -1){
        rep(i, a+k+1, c) swap(ans[a+k+1], ans[i+1]);
    }

    rep(i, 0, n){
        cout << ans[i] << ' ';
    }
    cout << endl;
   
    return 0;

}