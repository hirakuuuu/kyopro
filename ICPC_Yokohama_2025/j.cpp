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
        int n, m; cin >> n >> m;
        vector<string> s(n);
        rep(i, 0, n){
            cin >> s[i];
        }
        vector<string> ans = s;
        auto check = [&](vector<vector<char>> c) -> bool {
            bool f1 = true, f2 = true;
            // 行
            vector<int> row(n, -1);
            rep(i, 0, n){
                rep(j, 0, 2){
                    bool f = true;
                    rep(k, 0, m){
                        if(s[i][k] != '?' && s[i][k] != c[i%2][(j+k)%2]) f = false;
                    }
                    if(f) row[i] = j;
                }
                if(row[i] == -1) f1 = false;
            }
            if(f1){
                rep(i, 0, n){
                    rep(j, 0, m){
                        ans[i][j] = c[i%2][(j+row[i])%2];
                    }
                }
            }
            // 列
            vector<int> col(m, -1);
            rep(i, 0, m){
                rep(j, 0, 2){
                    bool f = true;
                    rep(k, 0, n){
                        if(s[k][i] != '?' && s[k][i] != c[i%2][(j+k)%2]) f = false;
                    }
                    if(f) col[i] = j;
                }
                if(col[i] == -1) f2 = false;
            }
            if(f2){
                rep(i, 0, m){
                    rep(j, 0, n){
                        ans[j][i] = c[i%2][(j+col[i])%2];
                    }
                }
            }
            return f1 || f2;
        };

        bool ok = false;
        if(check({{'I', 'P'}, {'C', 'C'}})) ok = true;
        if(check({{'C', 'C'}, {'I', 'P'}})) ok = true;
        if(check({{'I', 'C'}, {'P', 'C'}})) ok = true;
        if(check({{'P', 'C'}, {'I', 'C'}})) ok = true;

        if(ok){
            cout << "yes" << endl;
            rep(i, 0, n){
                cout << ans[i] << endl;
            }
        }else{
            cout << "no" << endl;
        }
    }

    return 0;
}