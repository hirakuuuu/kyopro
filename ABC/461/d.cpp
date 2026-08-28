#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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
    int h, w; cin >> h >> w;
    int k; cin >> k;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];

    vector<vector<int>> acc(h+1, vector<int>(w+1));
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            acc[i][j] = acc[i-1][j]+acc[i][j-1]-acc[i-1][j-1];
            if(s[i-1][j-1] == '1') acc[i][j]++;
        }
    }

    ll ans = 0;
    vector<ll> cnt(2*h*w+100);
    rep(c2, 1, w+1){
        rep(c1, 0, c2){
            rep(r, 0, h+1){
                int tmp = acc[r][c2]-acc[r][c1];
                ans += cnt[tmp-k+h*w];
                cnt[tmp+h*w]++;
            }
            rep(r, 0, h+1){
            int tmp = acc[r][c2]-acc[r][c1];
                cnt[tmp+h*w]--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}