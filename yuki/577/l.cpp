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
    vector<vector<int>> s(h, vector<int>(w));
    rep(i, 0, h){
        rep(j, 0, w){
            cin >> s[i][j];
        }
    }

    int r = 0;
    rep(i, 0, h){
        int sum = 0;
        rep(j, 0, w){
            sum += s[i][j];
        }
        r += sum%2;
    }
    int c = 0;
    rep(i, 0, w){
        int sum = 0;
        rep(j, 0, h){
            sum += s[j][i];
        }
        c += sum%2;
    }
    cout << max(r, c) << endl;

    return 0;
}