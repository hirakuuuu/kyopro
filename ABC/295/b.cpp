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
    int r, c; cin >> r >> c;
    vector<string> b(r);
    rep(i, 0, r){
        cin >> b[i];
    }

    vector<string> ans = b;
    rep(i, 0, r){
        rep(j, 0, c){
            if(b[i][j] == '.' || b[i][j] == '#') continue;
            int d = b[i][j]-'0';
            rep(ni, 0, r){
                rep(nj, 0, c){
                    if(abs(ni-i)+abs(nj-j) <= d){
                        ans[ni][nj] = '.';
                    }
                }
            }
        }
    }

    rep(i, 0, r){
        cout << ans[i] << endl;
    }
    return 0;
}