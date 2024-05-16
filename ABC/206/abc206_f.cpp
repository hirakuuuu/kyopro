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
grandy数
- ある盤面から遷移できない状態で最小の番号（mex）
- a\to aができず, b\to a (a < b) への遷移の意味が無くなる
- ゲームをいくつかの独立な問題に分割したときに、それぞれのgrandy数が求まっていれば、xorを取ることで、分割した状態のgrandy数が求まる

今回の問題でいうと、区間を分割したときに、遷移する状態は独立した2つの区間についてのゲームとなる
それぞれでgrandy数を求めておけば、そのxorで遷移先のgrandy数が求まる
後はmexを求めるが、状態数は高々ｎ個なので、setを使えば十分

*/

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> l(n), r(n);
        rep(i, 0, n){
            cin >> l[i] >> r[i];
        }
        vector<vector<int>> dp(102, vector<int>(102));
        rep(k, 1, 100){
            rep(i, 1, 100){
                if(i+k > 100) break;
                set<int> g;
                rep(j, 0, n){
                    if(i <= l[j] && r[j] <= i+k){
                        g.insert((dp[i][l[j]]^dp[r[j]][i+k]));
                    }
                }
                int f = 0;
                while(g.find(f) != g.end()) f++;
                dp[i][i+k] = f;
            }
        }
        if(dp[1][100]) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
    
    return 0;
}