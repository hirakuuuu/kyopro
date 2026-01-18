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
    int t; cin >> t;
    while(t--){
        int h, w; cin >> h >> w;
        vector<string> s(h);
        rep(i, 0, h){
            cin >> s[i];
        }
        vector<int> dp(1<<(w+1), IINF);
        int tmp = 0;
        rep(i, 0, w){
            tmp *= 2;
            if(s[0][i] == '#') tmp++;
        }
        dp[tmp] = 0;

        auto check = [&](int i) -> bool {
            return ((i&(1<<(w+1))) && (i&(1<<w)) && (i&2) && (i&1));
        };

        rep(i, 1, h){
            rep(j, 0, w){
                vector<int> ndp(1<<(w+1), IINF);
                if(j == 0){
                    rep(k, 0, 1<<(w+1)){
                        int nk = (k%(1<<w))*2+(s[i][j] == '#');
                        chmin(ndp[nk], dp[k]);
                    }
                }else{
                    rep(k, 0, 1<<(w+1)){
                        int nk = k*2+(s[i][j] == '#');
                        if(check(nk)){
                            chmin(ndp[nk-(1<<(w+1))], dp[k]+1);
                            chmin(ndp[nk-(1<<(w+1))-(1<<w)], dp[k]+1);
                            chmin(ndp[nk-(1<<(w+1))-2], dp[k]+1);
                            chmin(ndp[nk-(1<<(w+1))-1], dp[k]+1);
                        }else{
                            if(nk&(1<<(w+1))) nk -= (1<<(w+1));
                            chmin(ndp[nk], dp[k]);
                        }
                    }
                }
                swap(ndp, dp);
            }
        }

        int ans = IINF;
        rep(i, 0, 1<<(w+1)){
            chmin(ans, dp[i]);
        }
        cout << ans << endl;
    }
    
    return 0;
}