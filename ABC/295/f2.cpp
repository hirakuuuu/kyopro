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

    int t; cin >> t;
    vector<ll> ten(17);
    ten[0] = 1;
    rep(i, 1, 17) ten[i] = ten[i-1]*10;


    auto solve = [&](string s, ll x) -> ll {
        if(x <= 0) return 0LL;

        // s に関するオートマトン的なものを作る
        int n = (int)s.size();
        vector<vector<int>> nxt(n+1, vector<int>(10));
        rep(i, 0, n+1){
            string t = s.substr(0, i);
            rep(j, 0, 10){
                string tmp = t;
                tmp += (char)'0'+j;
                rrep(k, min(n, i+1), 0){
                    if(s.substr(0, k) == tmp.substr(i+1-k, k)){
                        // cout << i << ' ' << j << ' ' << k << endl;
                        nxt[i][j] = k;
                        break;
                    }
                }
            }
        }

        int o = 0;
        ll _x = x;
        while(_x){
            o++;
            _x /= 10;
        }
        if(o == 0) o = 1;
        string xs = to_string(x);

        vector<ll> dp(n+1);
        vector<ll> eq(n+1);
        rep(i, 1, 10){
            if(i < xs[0]-'0') dp[nxt[0][i]]++;
            else if(i == xs[0]-'0') eq[nxt[0][i]]++;
        }
        ll rest = x-(xs[0]-'0')*ten[o-1]+1;
        ll res = dp[n]*ten[o-1]+eq[n]*rest;
        rrep(i, o-2, 0){
            int num = xs[o-1-i]-'0';
            vector<ll> ndp(n+1);
            vector<ll> neq(n+1);
            dp[0]++;
            rep(j, 0, n+1){
                rep(k, 0, 10){
                    ndp[nxt[j][k]] += dp[j];
                }
            }
            ndp[nxt[0][0]]--;
            // rep(j, 0, n+1) cout << ndp[j] << ' ';
            // cout << endl;
            rep(k, 0, 10){
                if(k < num){
                    // cout << k << endl;
                    rep(j, 0, n+1){
                        ndp[nxt[j][k]] += eq[j];
                    }
                }else if(k == num){
                    rep(j, 0, n+1){
                        neq[nxt[j][k]] += eq[j];
                    }
                }
            }
            // rep(j, 0, n+1) cout << neq[j] << ' ';
            // cout << endl;
            res += ndp[n]*ten[i];
            rest -= num*ten[i];

            res += neq[n]*rest;

            swap(ndp, dp);
            swap(neq, eq);
        }

        return res;
    };


    while(t--){
        string s; cin >> s;
        ll l, r; cin >> l >> r;
        // cout << solve(s, r) << endl;
        // cout << solve(s, l-1) << endl;
        cout << solve(s, r)-solve(s, l-1) << endl;
    }



    return 0;
}