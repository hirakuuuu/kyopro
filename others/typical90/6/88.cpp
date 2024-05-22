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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
鳩ノ巣原理
*/

int main(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<vector<int>> ban(n, vector<int>(n));
    rep(i, 0, q){
        int x, y; cin >> x >> y;
        x--, y--;
        ban[x][y] = ban[y][x] = 1;
    }
    vector<vector<int>> dp(8889);
    rep(i, 0, n){
        if(!dp[a[i]].empty()){
            cout << 1 << endl;
            cout << dp[a[i]][0]+1 << endl;
            cout << 1 << endl;
            cout << i+1 << endl;
            return 0;
        }
        dp[a[i]]= {i};
    }
    rep(i, 2, n+1){
        rep(j, 0, 8889){
            if(dp[j].size() != i-1) continue;
            rep(k, dp[j].back()+1, n){
                bool ok = true;
                for(auto dd: dp[j]){
                    if(dd == k || ban[dd][k]){
                        ok = false;
                        break;
                    }
                }
                if(!ok) continue;
                if(!dp[j+a[k]].empty()){
                    vector<int> b = dp[j+a[k]];
                    vector<int> c = dp[j];
                    c.push_back(k);
                    cout << b.size() << endl;
                    for(auto bb: b){
                        cout << bb+1 << ' ';
                    }
                    cout << endl;
                    cout << c.size() << endl;
                    for(auto cc: c){
                        cout << cc+1 << ' ';
                    }
                    cout << endl;
                    return 0;
                }
                dp[j+a[k]] = dp[j];
                dp[j+a[k]].push_back(k);
            }
        }
    }
    return 0;
}