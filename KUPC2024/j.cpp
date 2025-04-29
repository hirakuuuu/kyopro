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
    ll l; cin >> l;

    string KUPC = "KUPC";
    vector<vector<int>> pos(4);
    rep(i, 0, 2*n){
        rep(j, 0, 4){
            if(KUPC[j] == s[i%n]){
                pos[j].push_back(i);
            }
        }
    }

    rep(j, 0, 4){
        if(pos[j].empty()){
            cout << -1 << endl;
            return 0;
        }
    }

    vector<vector<ll>> next(61, vector<ll>(n));
    vector<vector<ll>> plus(61, vector<ll>(n));
    rep(i, 0, n){
        int mx = 0;
        rep(j, 0, 4){
            int to = *upper_bound(pos[j].begin(), pos[j].end(), i);
            chmax(mx, to);
        }
        mx %= n;
        if(mx <= i) plus[0][i]++;
        next[0][i] = mx;
    }
    rep(i, 1, 61){
        rep(j, 0, n){
            next[i][j] = next[i-1][next[i-1][j]];
            plus[i][j] = plus[i-1][next[i-1][j]]+plus[i-1][j];
        }
    }
    
    ll ans = 0, now = n-1;
    rep(i, 0, 61){
        if((l>>i)&1){
            ans += plus[i][now];
            now = next[i][now];
        }
    }
    cout << ans << endl;



    return 0;
}