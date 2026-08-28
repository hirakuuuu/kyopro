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
    int n, l, r; cin >> n >> l >> r;
    string s; cin >> s;
    ll ans = 0;
    vector<vector<ll>> cnt(26, vector<ll>(n+1));
    rep(i, 0, 26){
        rep(j, 0, n){
            cnt[i][j+1] = cnt[i][j];
            if(s[j]-'a' == i) cnt[i][j+1]++;
        }
    }
    rep(i, 0, n){
        int tmp = s[i]-'a';
        ans += cnt[tmp][max(0, i-l+1)]-cnt[tmp][max(0, i-r)];
    }
    cout << ans << endl;
    
    return 0;
}