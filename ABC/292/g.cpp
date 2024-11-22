#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

mint dp[41][41][41][11][11];

int main(){
    int n, m; cin >> n >> m;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];

    rrep(i, m-1, 0){
        rep(l, 0, n+1){
            rep(r, l+1, n+1){
                rep(nl, 0, 10) rep(nr, nl+1, 10){
                    // dp[i][l][r][nl][nr] := s[l:r] を上から i 桁目を nl:nr を使って辞書順にする
                    // 分け方全通り試す必要がある？

                }
            }
        }
    }
    


    
    return 0;
}