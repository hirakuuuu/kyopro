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
    int h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];

    if(w > 14){
        vector<string> s_(w);
        rep(i, 0, h) rep(j, 0, w){
            s_[j] += s[i][j]; 
        }
        swap(s_, s);
        swap(h, w);
    }

    // w <= 14 なので 全部持って遷移する
    int thr = 1;
    rep(i, 0, w) thr *= 3;
    vector<mint> dp(thr);
    rep(i, 0, thr){
        vector<int> bit(w);
        int tmp = i;
        bool ok = true;
        rep(j, 0, w){
            if(s[0][j] == '?' || (s[0][j]-'0') == tmp%3){
                tmp /= 3;
                continue;
            }
            ok = false;
            break;
        }
        dp[i] = ok;
    }
    
    rep(i, 1, h){
        vector<mint> ndp(thr);
        rep(tmp, 0, thr){
            ndp[thr]
            rep(j, 0, w){
                if(s[i][j] == '?')

            }
        }


    }
    return 0;
}