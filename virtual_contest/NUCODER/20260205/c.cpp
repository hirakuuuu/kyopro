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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> y;
    rep(i, 1, n+1){
        if(n%i == 0) y.push_back(i);
    }

    int ans = IINF;
    for(auto yy: y){
        int l = n/yy;
        vector<vector<int>> cnt(l, vector<int>(26));
        rep(i, 0, n) cnt[i%l][s[i]-'a']++;
        int tot = 0;
        rep(i, 0, l){
            int mi = IINF;
            rep(j, 0, 26){
                chmin(mi, yy-cnt[i][j]);
            }
            tot += mi;
        }
        if(tot <= k) chmin(ans, l);
    }
    cout << ans << endl;
    return 0;
}