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
// https://atcoder.jp/contests/abc346/tasks/abc346_d

int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector<ll> c(n);
    rep(i, 0, n) cin >> c[i];
    vector<vector<ll>> l(2, vector<ll>(n)), r(2, vector<ll>(n));
    if(s[0] == '0') l[1][0] = c[0]; 
    else l[0][0] = c[0];
    rep(i, 1, n){
        if(s[i] == '0'){
            l[1][i] = l[0][i-1]+c[i];
            l[0][i] = l[1][i-1];
        }else{
            l[1][i] = l[0][i-1];
            l[0][i] = l[1][i-1]+c[i];
        }
    }
    if(s[n-1] == '0') r[1][n-1] = c[n-1]; 
    else r[0][n-1] = c[n-1];
    rrep(i, n-2, 0){
        if(s[i] == '0'){
            r[1][i] = r[0][i+1]+c[i];
            r[0][i] = r[1][i+1];
        }else{
            r[1][i] = r[0][i+1];
            r[0][i] = r[1][i+1]+c[i];
        }
    }

    ll ans = INF;
    rep(i, 0, n-1){
        rep(j, 0, 2){
            ll tmp = 0;
            if(s[i]-'0' != j) tmp += c[i];
            if(s[i+1]-'0' != j) tmp += c[i+1];
            if(i > 0) tmp += l[1-j][i-1];
            if(i < n-2) tmp += r[1-j][i+2];
            chmin(ans, tmp);
        }
    }
    cout << ans << endl;
    return 0;
}