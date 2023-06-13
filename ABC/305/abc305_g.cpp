#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc305/tasks/abc305_g

int main(){
    ll n, m; cin >> n >> m;
    vector<string> s(m);
    rep(i, 0, m) cin >> s[i];

    vector<string> all_s;
    rep(i, 0, 6){
        rep(j, 0, (1<<i)){
            string t; 
            rep(k, 0, i){
                t += 'a'+(j>>k&1);
            }
            all_s.push_back(t);
        }
    }

    ll cnt = all_s.size();
    vector<vector<ll>> next(cnt, vector<ll>(2));
    vector<vector<bool>> ok(cnt, vector<bool>(2, true));

    rep(i, 0, cnt){
        rep(j, 0, 2){
            string t = all_s[i];
            t += 'a'+j;

            rep(k, 0, m){
                if(t.size() >= s[k].size()){
                    if(t.substr(t.size()-s[k].size()) == s[k]){
                        ok[i][j] = false;
                    }
                }
            }

            if(ok[i][j]){
                if (t.size() == 6){
                    t.erase(t.begin());
                }
                rep(k, 0, cnt){
                    if(t == all_s[k]){
                        next[i][j] = k;
                    }
                }
            }
        }
    }

    vector<vector<ll>> mat(cnt, vector<ll>(cnt));
    rep(i, 0, cnt){
        rep(j, 0, 2){
            if(ok[i][j]){
                mat[i][next[i][j]] = 1;
            }
        }
    }
    auto matmal = [&](vector<vector<ll>> &A, vector<vector<ll>> &B){
        vector<vector<ll>> C(cnt, vector<ll>(cnt));
        rep(i, 0, cnt){
            rep(j, 0, cnt){
                rep(k, 0, cnt){
                    C[i][k] += A[i][j]*B[j][k];
                    C[i][k] %= MOD;
                }
            }
        }
        return C;
    };

    auto matpow = [&](vector<vector<ll>> &A, ll &N){
        vector<vector<ll>> C(cnt, vector<ll>(cnt));
        rep(i, 0, cnt){
            C[i][i] = 1;
        }

        ll tmp = N;
        while(tmp){
            if(tmp&1) C = matmal(C, A);
            A = matmal(A, A);
            tmp >>= 1;
        }

        return C;
    };

    vector<vector<ll>> result = matpow(mat, n);
    ll ans = 0;
    rep(i, 0, cnt){
        ans += result[0][i];
        ans %= MOD;
    }

    cout << ans << endl;



    
    return 0;
}