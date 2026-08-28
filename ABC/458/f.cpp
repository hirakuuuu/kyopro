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

/*
DPの遷移が線形式になる→行列累乗
*/

int main(){
    auto matmal = [&](vector<vector<mint>> A, vector<vector<mint>> B){
        vector<vector<mint>> C(A.size(), vector<mint>(B[0].size()));
        rep(i, 0, A.size()){
            rep(j, 0, B.size()){
                rep(l, 0, B[0].size()){
                    C[i][l] += (A[i][j]*B[j][l]);
                }
            }
        }
        return C;
    };

    auto matpow = [&](vector<vector<mint>> A, ll N){
        vector<vector<mint>> C(A.size(), vector<mint>(A[0].size()));
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


    int n, k; cin >> n >> k;

    vector<string> s(k);
    vector<int> siz(k);
    vector<string> ss = {""};
    rep(i, 0, k){
        cin >> s[i];
        siz[i] = (int)s[i].size();
    }
    rep(i, 0, k){
        rep(j, 0, s[i].size()-1){
            string t = s[i].substr(0, j+1);
            int st = (int)t.size();
            bool ok = true;
            rep(l, 0, k){
                if(s[l].size() <= t.size() && s[l] == t.substr(st-siz[l], siz[l])){
                    ok = false;
                }
            }
            if(ok){
                // cout << t << endl;
                ss.push_back(t);
            }
        }
    }
    sort(ss.begin(), ss.end());  
    int m = (int)ss.size();
    map<string, int> id;
    rep(i, 0, m){
        if(!id.count(ss[i])) id[ss[i]] = i;
    }

    // cout << m << endl;
    // rep(i, 0, m){
    //     cout << ss[i] << endl;
    // }

    // mxm 行列を作る
    vector<vector<mint>> x(m, vector<mint>(m));
    rep(i, 0, m){
        rep(j, 0, 26){
            string t = ss[i];
            t += (char)('a'+j);
            int st = (int)t.size();
            bool ok = true;
            rep(l, 0, k){
                if(t.size() >= s[l].size() && t.substr(st-siz[l], siz[l]) == s[l]) ok = false;
            }
            if(!ok) continue;
            // cout << i << ' ' << ss[i] << ' ' << t << endl;

            int sz = (int)t.size();
            int nxt = 0;
            rep(ii, 1, sz+1){
                if(id.count(t.substr(sz-ii, ii))){
                    nxt = id[t.substr(sz-ii, ii)];
                }
            }
            // cout << i << ' ' << nxt << endl;
            x[nxt][i] += 1;
        }
    }

    vector<vector<mint>> nx = matpow(x, n);
    mint ans = 0;
    rep(i, 0, m) ans += nx[i][0];
    cout << ans.val() << endl;

    return 0;
}