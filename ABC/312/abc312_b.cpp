#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc312/tasks/abc312_b

int main(){
    int n, m; cin >> n >> m;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];

    rep(i, 0, n-8){
        rep(j, 0, m-8){
            // 左上9マス
            bool f = true;
            rep(k, i, i+3){
                rep(l, j, j+3){
                    if(s[k][l] != '#') f = false;
                }
            }

            // 右下9マス
            rep(k, i+6, i+9){
                rep(l, j+6, j+9){
                    if(s[k][l] != '#') f = false;
                }
            }

            // 左上の隣接マス
            rep(k, i, i+3){
                if(s[k][j+3] == '#') f = false;
            }
            rep(k, j, j+3){
                if(s[i+3][k] == '#') f = false;
            }
            if(s[i+3][j+3] == '#') f = false;

            // 右下の隣接マス
            rep(k, i+6, i+9){
                if(s[k][j+5] == '#') f = false;
            }
            rep(k, j+6, j+9){
                if(s[i+5][k] == '#') f = false;
            }
            if(s[i+5][j+5] == '#') f = false;

            if(f) cout << i+1 << ' ' << j+1 << endl;
        }
    }
    
    return 0;
}