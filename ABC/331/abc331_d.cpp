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
// https://atcoder.jp/contests/abc331/tasks/abc331_d

ll solve(ll a, ll b, ll n, ll sum, vector<vector<ll>> &acc, vector<vector<ll>> &acc_){
    if(a < 0 || b < 0) return 0;
    ll res = 0;
    res += sum*((a+1)/n)*((b+1)/n);
    if(a%n != n-1) res += acc[(a)%n][n-1]*((b+1)/n);
    if(b%n != n-1) res += acc[n-1][(b)%n]*((a+1)/n);
    if(a%n != n-1 && b%n != n-1) res += acc[(a)%n][(b)%n];
    // cout << a << ' ' << b << ' ' << res << '\n';
    // cout << acc[(a)%n][n-1] << ' ' << acc[n-1][(b)%n] << ' ' << acc[(a)%n][(b)%n] << endl;
    return res;
}

int main(){
    int n, q; cin >> n >> q;
    vector<string> p(n);
    vector<vector<ll>> acc(n+1, vector<ll>(n+1));
    ll sum = 0;
    rep(i, 0, n){
        cin >> p[i];
        rep(j, 0, n){
            acc[i+1][j+1] = acc[i][j+1]+acc[i+1][j]-acc[i][j];
            if(p[i][j] == 'B') acc[i+1][j+1]++;
            if(p[i][j] == 'B') sum++;
        }
    }

    vector<vector<ll>> acc_(n, vector<ll>(n));
    rep(i, 0, n){
        rep(j, 0, n){
            acc_[i][j] = acc[i+1][j+1];
        }
    }
    swap(acc, acc_);


    

    while(q--){
        ll a, b, c, d; cin >> a >> b >> c >> d;
        ll ans = 0;
        ans += solve(c, d, n, sum, acc, acc_);
        ans -= solve(a-1, d, n, sum, acc, acc_);
        ans -= solve(c, b-1, n, sum, acc, acc_);
        ans += solve(a-1, b-1, n, sum, acc, acc_);
        cout << ans << endl;        
    }
    
    return 0;
}