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
    vector<string> s(h);
    int mxi = -1, mii = h;
    int mxj = -1, mij = w;
    rep(i, 0, h){
        cin >> s[i];
        rep(j, 0, w){
            if(s[i][j] == '#'){
                chmax(mxi, i);
                chmin(mii, i);
                chmax(mxj, j);
                chmin(mij, j);
            }
        }
    }

    rep(i, mii, mxi+1){
        rep(j, mij, mxj+1){
            if(s[i][j] == '.'){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}