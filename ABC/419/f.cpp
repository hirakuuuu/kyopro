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
    int n, l; cin >> n >> l;
    vector<string> s(n);
    vector<int> sz(n);
    rep(i, 0, n){
        cin >> s[i];
        sz[i] = (int)s[i].size();
    }

    vector<vector<vector<int>>> nxt(n);
    rep(i, 0, n){
        nxt[i].resize(sz[i]);
        rep(j, 0, sz[i]){
            nxt[i][j].resize(26);
            rep(c, 0, 26){
                string t = s[i].substr(0, j);
                t += (char)('a'+c);
                rrep(k, j+1, 0){
                    if(s[i].substr(0, k) == t.substr(j+1-k, k)){
                        nxt[i][j][c] = k;
                        break;
                    }
                }
                
            }
        }
    }

    map<vector<int>, mint> dp;
    dp[vector<int>(n, 0)] = 1;
    rep(_, 0, l){
        map<vector<int>, mint> ndp;
        for(auto [key, val]: dp){
            rep(c, 0, 26){
                vector<int> nkey = key;
                rep(i, 0, n){
                    if(key[i] == sz[i]) continue;
                    nkey[i] = nxt[i][key[i]][c];
                }
                ndp[nkey] += val;
            }
        }
        swap(ndp, dp);
        // cout << "############################################" << endl; 
        // for(auto [key, val]: dp){
        //     rep(i, 0, n){
        //         cout << key[i] << ' ';
        //     }
        //     cout << ": ";
        //     cout << val.val() << endl;
        // }
    }

    cout << dp[sz].val() << endl;
    
    return 0;
}