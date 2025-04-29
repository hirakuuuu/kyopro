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
    
    int n; cin >> n;
    vector<vector<char>> s(n, vector<char>(n, '.'));
    rep(i, 0, n){
        int j = n-1-i;
        if(i <= j){
            rep(k, i, j+1){
                rep(l, i, j+1){
                    if(i&1) s[k][l] = '.';
                    else s[k][l] = '#';
                }
            }
        }
    }

    rep(i, 0, n){
        rep(j, 0, n){
            cout << s[i][j];
        }
        cout << endl;
    }
    
    return 0;
}