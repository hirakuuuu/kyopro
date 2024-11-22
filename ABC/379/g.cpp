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
        vector<string> s_(w, string(h, '.'));
        rep(i, 0, w) rep(j, 0, h){
            s_[i][j] = s[j][i];
        }
        swap(s_, s);
        swap(h, w);
    }

    // w <= 14 より, 直近 w 個のマスの状態をもって DP する
    int tot = 1;
    rep(i, 0, w) tot *= 3;
    // 2 箇所以上同じ数字が隣接するパターンは現れない
    vector<string> p;
    unordered_map<string, int> id;
    rep(i, 0, tot){
        int tmp = i, pre = -1, cnt = 0;
        string t;
        rep(j, 0, w){
            if(pre == tmp%3) cnt++;
            pre = tmp%3;
            t += (char)('1'+tmp%3);
            tmp /= 3;
        }
        if(cnt >= 2) continue;
        p.push_back(t);
        id[t] = p.size()-1;
    }
    
    int m = (int)p.size();
    vector<mint> dp(m);
    rep(i, 0, m){
        bool ok = true;
        rep(j, 0, w){
            if(s[0][j] == '?' || s[0][j] == p[i][j]) continue;
            ok = false;
            break;
        }
        dp[i] = ok;
    }

    tot /= 3;
    rep(i, 1, h) rep(j, 0, w){
        vector<mint> ndp(m);
        // 隣接しているマスが異なっていないか
        rep(k, 0, m){
            bool ok = true;
            rep(l, 1, w){
                if(j+l != w && p[k][l] == p[k][l-1]) ok = false;
            }
            if(!ok) continue;

            // cout << i << ' ' << j << ' ' << p[k] << endl;

            if(s[i][j] != '?'){
                if(p[k][0] == s[i][j]) continue;
                if(j != 0 && p[k].back() == s[i][j]) continue;
                string tmp = p[k].substr(1)+s[i][j];
                ndp[id[tmp]] += dp[k];
            }else{
                rep(l, 0, 3){
                    if(p[k][0]-'1' == l) continue;
                    if(j != 0 && p[k].back()-'1' == l) continue;
                    string tmp = p[k].substr(1)+(char)('1'+l);
                    // cout << tmp << endl;
                    ndp[id[tmp]] += dp[k];
                }
            }
        }
        swap(dp, ndp);
    }

    mint ans = 0;
    rep(i, 0, m){
        // cout << p[i] << ' ' << dp[i].val() << endl;
        ans += dp[i];
    }
    cout << ans.val() << endl;
    
    return 0;
}