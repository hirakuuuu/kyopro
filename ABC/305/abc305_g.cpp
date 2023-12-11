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
        rep(j, 0, 1<<i){
            string t;
            rep(k, 0, i){
                if((j>>k)&1) t += 'b';
                else t += 'a';
            }
            all_s.push_back(t);
        }
    }

    ll total = all_s.size();
    vector<vector<ll>> next(total, vector<ll>(2));
    vector<vector<ll>> ok(total, vector<ll>(2, true));
    vector<vector<ll>> a(total, vector<ll>(total));
    rep(i, 0, total){
        rep(j, 0, 2){
            string tmp = all_s[i];
            tmp += (char)'a'+j;
            rep(k, 0, m){
                if(tmp.size() >= s[k].size()){
                    if(tmp.substr(tmp.size()-s[k].size()) == s[k]){
                        ok[i][j] = false;
                    }
                }
            }

            if(ok[i][j]){
                if(tmp.size() == 6){
                    tmp.erase(tmp.begin());
                }
                rep(k, 0, total){
                    if(tmp == all_s[k]){
                        next[i][j] = k;
                    }
                }
            }
        }
    }

    rep(i, 0, total){
        rep(j, 0, 2){
            if(ok[i][j]){
                a[i][next[i][j]] = 1LL;
            }
        }
    }

    auto matmal = [&](vector<vector<ll>> &A, vector<vector<ll>> &B){
        vector<vector<ll>> C(A.size(), vector<ll>(B[0].size()));
        rep(i, 0, A.size()){
            rep(j, 0, B.size()){
                rep(l, 0, B[0].size()){
                    C[i][l] += A[i][j]*B[j][l];
                    C[i][l] %= MOD;
                }
            }
        }
        return C;
    };

    auto matpow = [&](vector<vector<ll>> &A, ll N){
        vector<vector<ll>> C(A.size(), vector<ll>(A[0].size()));
        rep(i, 0, A.size()){
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

    vector<vector<ll>> result = matpow(a, n);
    ll ans = 0;
    rep(i, 0, total){
        ans += result[0][i];
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}