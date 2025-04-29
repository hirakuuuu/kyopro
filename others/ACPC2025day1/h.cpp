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
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    string t_rev = t;
    reverse(t_rev.begin(), t_rev.end());

    vector<vector<int>> dp_s_t_rev(n+1, vector<int>(m+1));
    rep(i, 1, n+1){
        rep(j, 1, m+1){
            if(s[i-1] == t_rev[j-1]) chmax(dp_s_t_rev[i][j], dp_s_t_rev[i-1][j-1]+1);
            chmax(dp_s_t_rev[i][j], dp_s_t_rev[i-1][j]);
            chmax(dp_s_t_rev[i][j], dp_s_t_rev[i][j-1]);
        }
    }

    vector<int> mi(max(n+1, m+1), IINF);
    rep(i, 0, n+1){
        rep(j, 0, m+1){
            chmin(mi[dp_s_t_rev[i][j]], j);
        }
    }

    int ans = -1;
    rep(l, 0, min(n, m)+1){
        if(mi[l] == IINF) continue;
        bool is_pal = true;
        rep(k, 0, n-l){
            if(s[l+k] != s[n-1-k]) is_pal = false;
        }
        if(is_pal){
            ans = n+l;
        }
    }

    if(mi[n] != IINF){
        int r = m-mi[n];
        string ts = t.substr(0, r);
        string ts_rev = ts;
        reverse(ts_rev.begin(), ts_rev.end());
        vector<vector<int>> dp_ts_ts_rev(ts.size()+1, vector<int>(ts_rev.size()+1));
        rep(i, 1, ts.size()+1){
            rep(j, 1, ts_rev.size()+1){
                if(ts[i-1] == ts_rev[j-1]) chmax(dp_ts_ts_rev[i][j], dp_ts_ts_rev[i-1][j-1]+1);
                chmax(dp_ts_ts_rev[i][j], dp_ts_ts_rev[i-1][j]);
                chmax(dp_ts_ts_rev[i][j], dp_ts_ts_rev[i][j-1]);
            }
        }

        int mx = 0;
        rep(i, 0, ts.size()+1){
            chmax(mx, dp_ts_ts_rev[i][(int)ts_rev.size()-i]*2);
            if((i > 0 && dp_ts_ts_rev[i][(int)ts_rev.size()-i] == dp_ts_ts_rev[i-1][(int)ts_rev.size()-i])
             || ((int)ts_rev.size()-i > 0 && dp_ts_ts_rev[i][(int)ts_rev.size()-i] == dp_ts_ts_rev[i][(int)ts_rev.size()-i-1])){
                chmax(mx, dp_ts_ts_rev[i][(int)ts_rev.size()-i]*2+1);
            }
        }
        chmax(ans, 2*n+mx);
    }
    cout << ans << endl;



    
    return 0;
}