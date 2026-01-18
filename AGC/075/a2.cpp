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


int main(){
    int n; cin >> n;

    vector<vector<int>> ans(n, vector<int>(n));

    if(n%2 == 0){
        rep(i, 0, n){
            rep(j, 0, n){
                ans[i][j] = i%2;
            }
        }
    }else{
        rep(i, 0, n){
            rep(j, 0, n-(i+1)/2*2) ans[i][j] = 1;
            rep(j, n-(i+1)/2*2, n) ans[i][j] = 0;
        }
    }
    rep(i, 0, n){
        rep(j, 0, n){
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}