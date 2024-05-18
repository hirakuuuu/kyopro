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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<vector<ll>> cnt(10, vector<ll>(10));
    rep(i, 1, n+1){
        string s = to_string(i);
        cnt[s[0]-'0'][s.back()-'0']++;
    }
    ll ans = 0;
    rep(i, 0, 10){
        rep(j, 0, 10){
            ans += cnt[i][j]*cnt[j][i];
        }
    }
    cout << ans << endl;
    
    return 0;
}