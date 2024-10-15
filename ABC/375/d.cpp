#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    string s; cin >> s;
    int n = (int)s.size();
    vector<vector<ll>> acc_l(n+1, vector<ll>(26)), acc_r(n+1, vector<ll>(26));
    rep(i, 1, n+1){
        rep(j, 0, 26){
            acc_l[i][j] = acc_l[i-1][j];
            if(s[i-1]-'A' == j) acc_l[i][j]++;
        }
    }
    rrep(i, n-1, 0){
        rep(j, 0, 26){
            acc_r[i][j] = acc_r[i+1][j];
            if(s[i]-'A' == j) acc_r[i][j]++;
        }
    }

    ll ans = 0;
    rep(i, 0, n){
        rep(j, 0, 26){
            ans += acc_l[i][j]*acc_r[i+1][j];
        }
    }
    cout << ans << endl;
    
    return 0;
}